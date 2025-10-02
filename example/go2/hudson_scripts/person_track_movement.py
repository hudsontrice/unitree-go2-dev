#!/usr/bin/env python3
"""Person tracking with forward/back distance regulation (simple version).

Based on: person_track_rotate.py (basic yaw tracker)
Adds: forward/back velocity to keep the person roughly the same apparent size.

How it works:
 1. Detect largest person (YOLO every N frames)
 2. Horizontal error -> yaw command (proportional + deadband + clamp)
 3. Bounding box width fraction vs target -> forward/back command (proportional + clamp + deadband)
 4. Optional smoothing to reduce jitter

Edit ONLY the CONFIG constants below.
"""
import time, cv2, numpy as np
from collections import deque
from unitree_sdk2py.core.channel import ChannelFactoryInitialize
from unitree_sdk2py.go2.sport.sport_client import SportClient
from unitree_sdk2py.go2.video.video_client import VideoClient
try:
    from ultralytics import YOLO
except ImportError:
    YOLO = None

# ---------------- CONFIG ----------------
IFACE = "enp3s0"          # network interface or None
MODEL = "yolov8l.pt"      # YOLO model (n = nano fastest), s, m, l, x available
CONF_THRESHOLD = 0.25      # detection confidence min
DETECT_INTERVAL = 10        # run detector every N frames (1 = every frame)

# Yaw control
KP_YAW = 0.9               # proportional gain for yaw
MAX_YAW = 0.8              # rad/s limit
DEADBAND_PX = 40           # ignore small horizontal errors (pixels)

# Distance (forward/back) control
TARGET_WIDTH_FRAC = 0.25   # desired fraction of image width occupied by person box
KP_DIST = 1.0              # proportional gain for distance
MAX_VX = 0.25              # max forward/back speed (m/s)
VX_DEADBAND = 0.02         # ignore tiny width errors
SMOOTH_VX = 0.85            # 0..1 smoothing factor (higher = slower response)

# General
COMMAND_HZ = 30.0          # command send frequency
SCALE = 1.0                # image resize factor (keep 1.0 at first)
MIN_BOX_AREA = 800         # smallest person box to consider
SMOOTH_WINDOW_YAW = 6      # moving average window for yaw smoothing

# ----------------------------------------

def load_model(path):
    if YOLO is None:
        raise SystemExit("ultralytics not installed: pip install ultralytics")
    return YOLO(path)

def main():
    # Channel + model
    ChannelFactoryInitialize(0, IFACE) if IFACE else ChannelFactoryInitialize(0)
    model = load_model(MODEL)
    names = model.names if hasattr(model,'names') else []
    person_ids = {i for i,n in enumerate(names) if 'person' in str(n).lower()} or {0}

    # Motion client
    sport = SportClient(); sport.SetTimeout(5); sport.Init()
    print('StandUp...'); sport.StandUp(); time.sleep(2)
    try: sport.BalanceStand(); time.sleep(0.3)
    except Exception: pass

    # Video client
    video = VideoClient(); video.SetTimeout(3.0); video.Init()
    code, data = video.GetImageSample()
    if code != 0:
        print('Camera error', code); return

    cv2.namedWindow('person_move', cv2.WINDOW_NORMAL)

    last_cmd_time = 0.0
    cmd_period = 1.0 / COMMAND_HZ
    last_det_frame = -1
    frame_idx = 0

    # Smoothing buffers
    yaw_buf = deque(maxlen=SMOOTH_WINDOW_YAW)
    prev_vx = 0.0

    try:
        while True:
            code, data = video.GetImageSample()
            if code != 0:
                print('Stream ended', code); break
            arr = np.frombuffer(bytes(data), dtype=np.uint8)
            frame = cv2.imdecode(arr, cv2.IMREAD_COLOR)
            if frame is None:
                continue
            frame_disp = frame if SCALE == 1.0 else cv2.resize(frame,(0,0),fx=SCALE,fy=SCALE)

            # Detection step (every DETECT_INTERVAL frames)
            best = None
            if (frame_idx - last_det_frame) >= DETECT_INTERVAL:
                rgb = cv2.cvtColor(frame_disp, cv2.COLOR_BGR2RGB)
                results = model.predict(rgb, conf=CONF_THRESHOLD, verbose=False)
                last_det_frame = frame_idx
                if results:
                    r0 = results[0]
                    if r0.boxes is not None:
                        for b in r0.boxes:
                            cls = int(b.cls[0].item())
                            if cls not in person_ids: continue
                            conf = float(b.conf[0].item())
                            if conf < CONF_THRESHOLD: continue
                            x1,y1,x2,y2 = b.xyxy[0].tolist()
                            area = (x2-x1)*(y2-y1)
                            if area < MIN_BOX_AREA: continue
                            if best is None or area > best[0]:
                                best = (area, (x1,y1,x2,y2,conf))

            W = frame_disp.shape[1]
            center_x = W/2.0
            yaw_cmd = 0.0
            vx_cmd = 0.0
            status = 'SCAN'

            if best:
                status = 'TRACK'
                area,(x1,y1,x2,y2,conf) = best
                cx = 0.5*(x1+x2)
                error_px = cx - center_x
                # Yaw control
                if abs(error_px) > DEADBAND_PX:
                    norm_err = error_px / (W/2.0)
                    yaw_cmd = max(-MAX_YAW, min(MAX_YAW, -KP_YAW * norm_err))
                # Distance control
                box_w = (x2 - x1)
                width_frac = box_w / W
                dist_err = width_frac - TARGET_WIDTH_FRAC
                if abs(dist_err) > VX_DEADBAND:
                    raw_vx = -KP_DIST * dist_err  # object small => dist_err<0 => forward (+)
                    vx_cmd = max(-MAX_VX, min(MAX_VX, raw_vx))
                # Draw overlays
                cv2.rectangle(frame_disp,(int(x1),int(y1)),(int(x2),int(y2)),(0,0,255),2)
                cv2.circle(frame_disp,(int(cx),int(0.5*(y1+y2))),4,(0,255,255),-1)
                cv2.line(frame_disp,(int(center_x),0),(int(center_x),frame_disp.shape[0]),(255,255,0),1)
                cv2.putText(frame_disp,f'w%:{width_frac*100:.1f}',(10,42),cv2.FONT_HERSHEY_SIMPLEX,0.5,(0,200,255),1,cv2.LINE_AA)

            # Smooth yaw (moving average)
            yaw_buf.append(yaw_cmd)
            smoothed_yaw = sum(yaw_buf)/len(yaw_buf)
            # Smooth vx (simple exponential)
            prev_vx = prev_vx + SMOOTH_VX * (vx_cmd - prev_vx)

            # Send motion
            now = time.time()
            if now - last_cmd_time >= cmd_period:
                sport.Move(prev_vx, 0.0, smoothed_yaw)
                last_cmd_time = now

            # HUD
            cv2.putText(frame_disp,f"{status} yaw:{smoothed_yaw:+.2f} vx:{prev_vx:+.2f}",(10,20),cv2.FONT_HERSHEY_SIMPLEX,0.55,(0,255,0) if status=='TRACK' else (0,200,200),2,cv2.LINE_AA)
            cv2.imshow('person_move', frame_disp)
            key = cv2.waitKey(1) & 0xFF
            if key in (27, ord('q')):
                print('Exit key pressed'); break

            frame_idx += 1
    except KeyboardInterrupt:
        print('Ctrl+C')
    finally:
        try:
            sport.StopMove(); time.sleep(0.2)
            sport.StandDown(); time.sleep(1.0)
            sport.Damp()
        except Exception:
            pass
        cv2.destroyAllWindows(); print('Done.')

if __name__ == '__main__':
    main()
