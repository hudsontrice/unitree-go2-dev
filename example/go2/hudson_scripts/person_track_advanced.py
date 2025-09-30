#!/usr/bin/env python3
"""Advanced person tracking script (full features, original version).

Keeps largest detected person centered using YOLOv8. Includes:
- CLI arguments for tuning
- Scanning motion when no person seen
- Hysteresis (acquire frames + hold time)
- Display annotations + snapshots

For a minimal learning version see: spin_detect_people_led.py
"""
import sys, time, argparse, cv2, numpy as np
from unitree_sdk2py.core.channel import ChannelFactoryInitialize
from unitree_sdk2py.go2.sport.sport_client import SportClient
from unitree_sdk2py.go2.video.video_client import VideoClient

try:
    from ultralytics import YOLO
except ImportError:
    YOLO = None


def parse_args():
    p = argparse.ArgumentParser()
    p.add_argument('iface', nargs='?', default=None)
    p.add_argument('--model', default='yolov8n.pt')
    p.add_argument('--conf', type=float, default=0.25)
    p.add_argument('--iou', type=float, default=0.45)
    p.add_argument('--detect-interval', type=int, default=2)
    p.add_argument('--scale', type=float, default=1.0)
    p.add_argument('--resize-detect', action='store_true')
    p.add_argument('--kp', type=float, default=0.9)
    p.add_argument('--max-yaw', type=float, default=0.8)
    p.add_argument('--deadband-px', type=int, default=40)
    p.add_argument('--scan-yaw', type=float, default=0.35)
    p.add_argument('--scan-timeout', type=float, default=1.0)
    p.add_argument('--command-hz', type=float, default=30.0)
    p.add_argument('--max-fps', type=int, default=30)
    p.add_argument('--no-display', action='store_true')
    p.add_argument('--acquire-frames', type=int, default=3)
    p.add_argument('--hold-time', type=float, default=0.5)
    return p.parse_args()


def load_model(path):
    if YOLO is None:
        print('[ERROR] ultralytics not installed: pip install ultralytics')
        sys.exit(2)
    try:
        return YOLO(path)
    except Exception as e:
        print('[ERROR] model load failed:', e)
        sys.exit(2)


def main():
    args = parse_args()
    ChannelFactoryInitialize(0, args.iface) if args.iface else ChannelFactoryInitialize(0)
    model = load_model(args.model)
    names = model.names if hasattr(model,'names') else []
    person_ids = {i for i,n in enumerate(names) if 'person' in str(n).lower()} or {0}

    sc = SportClient(); sc.SetTimeout(5); sc.Init(); print('StandUp...'); sc.StandUp(); time.sleep(2)
    try: sc.BalanceStand(); time.sleep(0.5)
    except Exception: pass
    try: sc.SpeedLevel(1)
    except Exception: pass

    vc = VideoClient(); vc.SetTimeout(3.0); vc.Init()
    code, data = vc.GetImageSample()
    if code != 0:
        print('[ERROR] initial GetImageSample code=', code); return
    if not args.no_display:
        cv2.namedWindow('person_track', cv2.WINDOW_NORMAL)

    frame_idx=0; last_det_frame=-1; last_detection_time=0.0
    consec_detect=0; tracking_active=False; last_target_cx=None
    cmd_period = 1.0 / max(1e-3, args.command_hz); last_cmd_send=0.0
    target_interval = 1.0 / max(1, args.max_fps)
    scan_dir=1; scan_switch_interval=6.0; last_scan_switch=time.time()

    try:
        while True:
            loop_start=time.time()
            code,data=vc.GetImageSample()
            if code!=0: break
            arr=np.frombuffer(bytes(data),dtype=np.uint8)
            frame_full=cv2.imdecode(arr,cv2.IMREAD_COLOR)
            if frame_full is None: continue
            frame_disp=frame_full; frame_for_det=frame_full
            if args.scale!=1.0:
                frame_disp=cv2.resize(frame_full,(0,0),fx=args.scale,fy=args.scale,interpolation=cv2.INTER_AREA)
                if args.resize_detect: frame_for_det=frame_disp
            run_det = (frame_idx - last_det_frame) >= args.detect_interval
            best=None
            if run_det:
                rgb=cv2.cvtColor(frame_for_det,cv2.COLOR_BGR2RGB)
                results=model.predict(rgb,conf=args.conf,iou=args.iou,verbose=False)
                if results:
                    r0=results[0]
                    if r0.boxes is not None:
                        for b in r0.boxes:
                            cls=int(b.cls[0].item())
                            if cls not in person_ids: continue
                            conf=float(b.conf[0].item())
                            if conf < args.conf: continue
                            x1,y1,x2,y2=b.xyxy[0].tolist()
                            area=(x2-x1)*(y2-y1)
                            if best is None or area>best[0]:
                                best=(area,[x1,y1,x2,y2,conf,cls])
                last_det_frame=frame_idx
                if best:
                    last_detection_time=time.time(); consec_detect+=1
                    if not tracking_active and consec_detect>=max(1,args.acquire_frames):
                        tracking_active=True
                else:
                    consec_detect=0

            yaw_cmd=0.0; tracking=False; disp_w=frame_disp.shape[1]
            if best:
                x1,y1,x2,y2,conf,cls=best[1]
                if (frame_for_det is frame_full) and (frame_disp is not frame_full):
                    sx=frame_disp.shape[1]/frame_full.shape[1]; sy=frame_disp.shape[0]/frame_full.shape[0]
                    x1,y1,x2,y2=x1*sx,y1*sy,x2*sx,y2*sy
                cx=0.5*(x1+x2); last_target_cx=cx; error_px=cx-disp_w/2.0
                if tracking_active:
                    if abs(error_px)>args.deadband_px:
                        norm_err=error_px/(disp_w/2.0)
                        yaw_cmd=max(-args.max_yaw,min(args.max_yaw,-args.kp*norm_err))
                    tracking=True
                if not args.no_display:
                    cv2.rectangle(frame_disp,(int(x1),int(y1)),(int(x2),int(y2)),(0,0,255),2)
                    cv2.line(frame_disp,(disp_w//2,0),(disp_w//2,frame_disp.shape[0]),(255,255,0),1)
                    cv2.circle(frame_disp,(int(cx),int(0.5*(y1+y2))),4,(0,255,255),-1)
            else:
                if tracking_active and (time.time()-last_detection_time)<=args.hold_time and last_target_cx is not None:
                    error_px=last_target_cx-disp_w/2.0
                    if abs(error_px)>args.deadband_px:
                        norm_err=error_px/(disp_w/2.0)
                        yaw_cmd=max(-args.max_yaw,min(args.max_yaw,-args.kp*norm_err))
                    tracking=True
                elif tracking_active and (time.time()-last_detection_time)>args.hold_time:
                    tracking_active=False
                if not tracking and (time.time()-last_detection_time)>=args.scan_timeout:
                    yaw_cmd=scan_dir*args.scan_yaw
                    if (time.time()-last_scan_switch)>=scan_switch_interval:
                        scan_dir*=-1; last_scan_switch=time.time()

            now=time.time()
            if now-last_cmd_send>=cmd_period:
                sc.Move(0.0,0.0,yaw_cmd); last_cmd_send=now

            if not args.no_display:
                status='TRACK' if tracking else 'SCAN'
                cv2.putText(frame_disp,f'{status} yaw:{yaw_cmd:+.2f}',(10,20),cv2.FONT_HERSHEY_SIMPLEX,0.6,(0,255,0) if tracking else (200,200,0),2,cv2.LINE_AA)
                cv2.imshow('person_track',frame_disp)
                key=cv2.waitKey(1)&0xFF
                if key in (27,ord('q')): break
                elif key==ord('s'):
                    cv2.imwrite(f'track_{int(time.time())}.png',frame_disp)

            elapsed=time.time()-loop_start
            if elapsed<target_interval: time.sleep(target_interval-elapsed)
            frame_idx+=1
    except KeyboardInterrupt:
        print('KeyboardInterrupt - stopping')
    finally:
        try:
            sc.StopMove(); time.sleep(0.2); sc.StandDown(); time.sleep(1.0); sc.Damp()
        except Exception: pass
        if not args.no_display:
            cv2.destroyAllWindows()
        print('Done.')

if __name__=='__main__':
    main()
