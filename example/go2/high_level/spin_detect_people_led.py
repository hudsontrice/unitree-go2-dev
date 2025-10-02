#!/usr/bin/env python3
"""Spin the robot continuously while performing YOLOv8 person detection; pulse LEDs red when people seen.

DISCLAIMER:
  This uses a low-level "rt/lowcmd" publisher ONLY to drive the RGB LED bytes.
  Publishing LowCmd messages can, on some firmware, pull the robot into low-level mode
  and interfere with high-level SportClient commands. If you observe loss of motion
  or gait issues, re-run without --led or power-cycle. By default LEDs are enabled;
  you can disable them with --no-led.

Prereqs:
  pip install ultralytics opencv-python numpy

Usage:
    python3 spin_detect_people_led.py [iface] --model yolov8n.pt --yaw-rate 0.6 --scale 0.7
    (Runs continuous rotations until Ctrl+C)

Keys:
  q / ESC : abort early
  s       : save current annotated frame

LED Policy:
    - Any person (class name contains 'person') above --conf => LEDs pulse RED (sinusoidal brightness)
    - No person => LEDs solid GREEN (idle)
    - On exit => LEDs set to BLUE

Internals:
    - Reuses yaw integration logic from fullspin_test.
    - Single loop pulls video frames, performs detection every N frames (--detect-interval),
        streams yaw velocity command at COMMAND_HZ, resets after each full rotation for continuous scanning.
"""
import sys, time, math, argparse, os
import cv2, numpy as np
from unitree_sdk2py.core.channel import ChannelFactoryInitialize, ChannelSubscriber, ChannelPublisher
from unitree_sdk2py.go2.sport.sport_client import SportClient
from unitree_sdk2py.go2.video.video_client import VideoClient
from unitree_sdk2py.idl.unitree_go.msg.dds_ import SportModeState_, LowCmd_
from unitree_sdk2py.idl.default import unitree_go_msg_dds__LowCmd_
from unitree_sdk2py.utils.crc import CRC

try:
    from ultralytics import YOLO
except ImportError:
    YOLO = None

STATE_TOPICS = ["rt/sportmodestate", "sportmodestate", "rt/sportmode/state", "rt/highstate", "highstate"]


def parse_args():
    p = argparse.ArgumentParser()
    p.add_argument('iface', nargs='?', default=None, help='Network interface (e.g. enp3s0)')
    p.add_argument('--model', default='yolov8n.pt', help='YOLOv8 weights path/name')
    p.add_argument('--conf', type=float, default=0.25, help='Detection confidence threshold')
    p.add_argument('--iou', type=float, default=0.45, help='NMS IoU threshold')
    p.add_argument('--detect-interval', type=int, default=2, help='Run detector every N frames (>=1)')
    p.add_argument('--scale', type=float, default=1.0, help='Display scale factor')
    p.add_argument('--yaw-rate', type=float, default=0.6, help='Spin yaw rate (rad/s)')
    p.add_argument('--target-deg', type=float, default=360.0, help='Target spin degrees')
    p.add_argument('--command-hz', type=float, default=30.0, help='Command streaming rate')
    p.add_argument('--max-fps', type=int, default=30, help='Video pull cap FPS')
    p.add_argument('--no-led', action='store_true', help='Disable LED publishing')
    p.add_argument('--save', dest='save_path', default=None, help='Optional annotated video save path')
    p.add_argument('--resize-detect', action='store_true', help='Run detection on scaled frame for speed')
    p.add_argument('--pulse-period', type=float, default=0.8, help='LED pulse period (s) when detecting people')
    p.add_argument('--beep', action='store_true', help='Terminal bell beep on person detection events')
    p.add_argument('--beep-repeat', type=float, default=5.0, help='Repeat beep every N seconds while person present (set 0 to disable repeat)')
    p.add_argument('--alternate', action='store_true', help='Alternate spin direction each rotation')
    return p.parse_args()


def load_model(path):
    if YOLO is None:
        print('[ERROR] ultralytics not installed. Run: pip install ultralytics')
        sys.exit(2)
    try:
        return YOLO(path)
    except Exception as e:
        print('[ERROR] model load failed:', e)
        sys.exit(2)


def get_state_sub():
    for t in STATE_TOPICS:
        try:
            sub = ChannelSubscriber(t, SportModeState_)
            sub.Init()
            sample = sub.Read(0.05)
            return sub, t
        except Exception:
            continue
    return None, None


def normalize_angle(a):
    while a <= -math.pi:
        a += 2*math.pi
    while a > math.pi:
        a -= 2*math.pi
    return a

class LedPublisher:
    def __init__(self, enabled=True):
        self.enabled = enabled
        if not enabled:
            return
        self.pub = ChannelPublisher("rt/lowcmd", LowCmd_)
        self.pub.Init()
        self.crc = CRC()
        self.cmd = unitree_go_msg_dds__LowCmd_()
        # Basic header like examples
        self.cmd.head[0] = 0xFE
        self.cmd.head[1] = 0xEF
        self.cmd.level_flag = 0x00  # try keep out of full low-level override
        # Leave motor_cmd untouched (all zeros)
        self.last = None

    def set_color(self, r, g, b):
        if not self.enabled:
            return
        key = (r,g,b)
        if key == self.last:
            return
        for i in range(0, 12, 3):
            self.cmd.led[i] = r & 0xFF
            self.cmd.led[i+1] = g & 0xFF
            self.cmd.led[i+2] = b & 0xFF
        self.cmd.crc = self.crc.Crc(self.cmd)
        try:
            self.pub.Write(self.cmd)
            self.last = key
        except Exception as e:
            print('[WARN] LED publish failed:', e)


def create_writer(path, w, h, fps):
    if not path:
        return None
    ext = os.path.splitext(path)[1].lower()
    if ext == '':
        path += '.mp4'; ext = '.mp4'
    fourccs = ['mp4v','avc1','H264','MJPG'] if ext in ('.mp4','.m4v') else ['MJPG','XVID','mp4v']
    for f in fourccs:
        try:
            wri = cv2.VideoWriter(path, cv2.VideoWriter_fourcc(*f), fps, (w,h))
            if wri.isOpened():
                print(f'[INFO] video writer open ({f}) -> {path}')
                return wri
        except Exception: pass
    print('[WARN] cannot open writer'); return None


def main():
    args = parse_args()
    if args.iface:
        ChannelFactoryInitialize(0, args.iface)
    else:
        ChannelFactoryInitialize(0)

    model = load_model(args.model)
    names = model.names if hasattr(model,'names') else []
    person_class_ids = {i for i,n in enumerate(names) if 'person' in str(n).lower()}
    if not person_class_ids:
        # YOLO COCO usually person id 0
        person_class_ids = {0}

    sc = SportClient(); sc.SetTimeout(5); sc.Init()
    print('StandUp...'); sc.StandUp(); time.sleep(2)
    try:
        sc.BalanceStand(); time.sleep(0.5)
    except Exception: pass
    try:
        sc.SpeedLevel(1)
    except Exception: pass

    sub, topic = get_state_sub()
    if topic: print('[INFO] state topic:', topic)
    else: print('[WARN] no state topic; timing spin only')

    vc = VideoClient(); vc.SetTimeout(3.0); vc.Init()
    code, data = vc.GetImageSample()
    if code != 0:
        print('[ERROR] initial GetImageSample code=', code)
        return

    led = LedPublisher(enabled=not args.no_led)
    led.set_color(0,255,0)  # green idle

    cv2.namedWindow('spin_detect', cv2.WINDOW_NORMAL)

    target_rad = math.radians(args.target_deg)
    accumulated = 0.0
    start_yaw = None
    last_yaw = None
    spin_dir = 1
    rotation_count = 0
    cmd_period = 1.0/args.command_hz
    last_cmd_t = 0.0
    frame_idx = 0
    last_det_frame = -1
    detections_cache = None
    prev_people = False
    last_beep_time = 0.0

    writer = None
    fps_counter = 0
    fps_last = time.time(); fps_val=0.0
    target_interval = 1.0/max(1,args.max_fps)

    def read_yaw():
        if not sub: return None
        s = sub.Read(0.0)
        if not s: return None
        imu = getattr(s,'imu_state',None)
        if not imu: return None
        return imu.rpy[2]

    try:
        while True:
            loop_start = time.time()
            # Pull frame
            code, data = vc.GetImageSample()
            if code != 0:
                print('[INFO] video ended code=', code); break
            raw = np.frombuffer(bytes(data), dtype=np.uint8)
            frame_full = cv2.imdecode(raw, cv2.IMREAD_COLOR)
            if frame_full is None:
                continue
            frame_for_det = frame_full
            frame_disp = frame_full
            if args.scale != 1.0:
                frame_disp = cv2.resize(frame_full,(0,0),fx=args.scale,fy=args.scale,interpolation=cv2.INTER_AREA)
                if args.resize_detect:
                    frame_for_det = frame_disp
            run_det = (frame_idx - last_det_frame) >= args.detect_interval
            people_present = False
            if run_det:
                rgb = cv2.cvtColor(frame_for_det, cv2.COLOR_BGR2RGB)
                results = model.predict(rgb, conf=args.conf, iou=args.iou, verbose=False)
                dets = []
                if results:
                    r0 = results[0]
                    if r0.boxes is not None and len(r0.boxes)>0:
                        for b in r0.boxes:
                            xyxy = b.xyxy[0].tolist(); conf = b.conf[0].item(); cls = int(b.cls[0].item())
                            dets.append(xyxy + [conf, cls])
                            if cls in person_class_ids and conf >= args.conf:
                                people_present = True
                detections_cache = dets
                last_det_frame = frame_idx
            else:
                # reuse cache; determine if any person stored
                if detections_cache:
                    for d in detections_cache:
                        cls = int(d[5]); conf = d[4]
                        if cls in person_class_ids and conf >= args.conf:
                            people_present = True; break
            # Scale boxes if detection on full-res but display scaled
            dets_draw = []
            if detections_cache:
                if (frame_for_det is frame_full) and (frame_disp is not frame_full):
                    sx = frame_disp.shape[1]/frame_full.shape[1]
                    sy = frame_disp.shape[0]/frame_full.shape[0]
                    for d in detections_cache:
                        x1,y1,x2,y2,conf,cls = d
                        dets_draw.append([x1*sx,y1*sy,x2*sx,y2*sy,conf,cls])
                else:
                    dets_draw = detections_cache
            # Annotate
            for d in dets_draw:
                x1,y1,x2,y2,conf,cls = d
                color = (0,0,255) if (cls in person_class_ids) else (0,255,0)
                cv2.rectangle(frame_disp,(int(x1),int(y1)),(int(x2),int(y2)),color,2)
            status_txt = 'PERSON' if people_present else 'clear'
            cv2.putText(frame_disp,f'{status_txt}',(10,20),cv2.FONT_HERSHEY_SIMPLEX,0.7,(0,0,255) if people_present else (0,255,0),2,cv2.LINE_AA)
            # Yaw integration / spin control
            yaw = read_yaw()
            if yaw is not None and start_yaw is None:
                start_yaw = yaw; last_yaw = yaw
            if yaw is not None and last_yaw is not None:
                dyaw = normalize_angle(yaw - last_yaw)
                accumulated += dyaw * spin_dir
                last_yaw = yaw
            # Command spin at set rate
            now = time.time()
            if accumulated < target_rad:
                if now - last_cmd_t >= cmd_period:
                    sc.Move(0,0, spin_dir*args.yaw_rate)
                    last_cmd_t = now
            else:
                # Completed one rotation; reset for continuous scanning
                rotation_count += 1
                print(f'[INFO] rotation {rotation_count} complete ({math.degrees(accumulated):.1f} deg)')
                accumulated = 0.0
                start_yaw = None
                last_yaw = None
                if args.alternate:
                    spin_dir *= -1
                # brief settle
                sc.StopMove(); time.sleep(0.15)
                last_cmd_t = 0.0
                continue
            # LEDs
            if not args.no_led:
                if people_present:
                    # Pulsing red brightness
                    phase = (time.time() % args.pulse_period) / max(1e-6, args.pulse_period)
                    # Sinusoidal 0..1
                    intensity = 0.5 * (1 + math.sin(2*math.pi*phase))
                    r = int(40 + 215 * intensity)  # keep a minimum glow
                    led.set_color(r,0,0)
                else:
                    led.set_color(0,255,0)

            # Beep logic
            if args.beep and people_present:
                now_t = time.time()
                if (not prev_people) or (args.beep_repeat > 0 and (now_t - last_beep_time) >= args.beep_repeat):
                    try:
                        sys.stdout.write('\a')
                        sys.stdout.flush()
                    except Exception:
                        pass
                    last_beep_time = now_t
            prev_people = people_present
            # FPS
            fps_counter += 1
            if now - fps_last >= 1.0:
                fps_val = fps_counter / (now - fps_last)
                fps_counter = 0; fps_last = now
            cv2.setWindowTitle('spin_detect', f'SpinDetect {frame_disp.shape[1]}x{frame_disp.shape[0]} fps:{fps_val:.1f} spun:{math.degrees(accumulated):.1f}/{args.target_deg}')
            cv2.imshow('spin_detect', frame_disp)
            if writer is None and args.save_path:
                writer = create_writer(args.save_path, frame_disp.shape[1], frame_disp.shape[0], min(args.max_fps,30))
            if writer is not None:
                writer.write(frame_disp)
            key = cv2.waitKey(1) & 0xFF
            if key in (27, ord('q')):
                print('User abort'); break
            elif key == ord('s'):
                fn = f'spin_frame_{int(time.time())}.png'; cv2.imwrite(fn, frame_disp); print('[INFO] saved', fn)
            # Throttle video pull
            elapsed = time.time() - loop_start
            if elapsed < target_interval:
                time.sleep(target_interval - elapsed)
            frame_idx += 1
    finally:
        sc.StopMove(); time.sleep(0.2)
        try:
            sc.StandDown(); time.sleep(1.5)
            sc.Damp()
        except Exception: pass
        if not args.no_led:
            led.set_color(0,0,255)  # blue end
        if writer is not None:
            writer.release()
        cv2.destroyAllWindows()
        if start_yaw is not None:
            print(f'Spun approx {math.degrees(accumulated):.1f} deg')
        print('Done.')

if __name__ == '__main__':
    main()
