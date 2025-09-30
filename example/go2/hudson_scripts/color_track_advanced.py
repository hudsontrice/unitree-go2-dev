#!/usr/bin/env python3
# This is the previous (full-feature) version of color_track.py kept as a backup/advanced reference.
# It contains more options (hysteresis, auto HSV calibration, distance smoothing, etc.).
# The simplified learning version now lives in color_track.py

import sys, time, math, numpy as np, cv2
from unitree_sdk2py.core.channel import ChannelFactoryInitialize
from unitree_sdk2py.go2.sport.sport_client import SportClient
from unitree_sdk2py.go2.video.video_client import VideoClient

COLOR_PRESETS = {
    'red':   [ ( (0,100,70), (10,255,255) ), ( (160,100,70), (179,255,255) ) ],
    'blue':  [ ( (100,120,60), (130,255,255) ) ],
    'green': [ ( (35,60,60), (85,255,255) ) ],
    'yellow':[ ( (20,110,110), (32,255,255) ) ],
    'orange':[ ( (10,130,120), (22,255,255) ) ],
    'purple':[ ( (130,80,60), (155,255,255) ) ],
    'pink':  [ ( (150,60,120), (170,255,255) ) ],
}

IFACE = "enp3s0"
PRESET = "blue"
CUSTOM_HSV_RANGES = None
SCALE = 0.8
RESIZE_DETECT = True
BLUR = 5
ERODE_ITERS = 1
DILATE_ITERS = 2
MIN_AREA = 1500
KP = 0.9
MAX_YAW = 0.8
DEADBAND_PX = 40
ACQUIRE_FRAMES = 3
HOLD_TIME = 0.5
SCAN_YAW = 0.35
SCAN_TIMEOUT = 1.0
COMMAND_HZ = 30.0
MAX_FPS = 30
NO_DISPLAY = False
DEBUG = False
ENABLE_DISTANCE_CTRL = True
TARGET_WIDTH_FRAC = 0.25
KP_DIST = 1.2
MAX_VX = 0.25
VX_DEADBAND = 0.02
DIST_SMOOTH = 0.3
APPROACH_ONLY = False
CAL_PATCH_HALF = 10
CAL_H_PAD = 8
CAL_S_PAD = 40
CAL_V_PAD = 40

def build_mask(hsv_img, ranges):
    mask_total = None
    for (l,u) in ranges:
        lower = np.array(l, dtype=np.uint8)
        upper = np.array(u, dtype=np.uint8)
        mask = cv2.inRange(hsv_img, lower, upper)
        mask_total = mask if mask_total is None else cv2.bitwise_or(mask_total, mask)
    return mask_total if mask_total is not None else np.zeros(hsv_img.shape[:2], dtype=np.uint8)

def auto_calibrate(center_patch_hsv, h_pad=8, s_pad=40, v_pad=40):
    h = center_patch_hsv[...,0].astype(np.int32)
    s = center_patch_hsv[...,1].astype(np.int32)
    v = center_patch_hsv[...,2].astype(np.int32)
    h_min, h_max = max(0, h.min()-h_pad), min(179, h.max()+h_pad)
    s_min, s_max = max(0, s.min()-s_pad), min(255, s.max()+s_pad)
    v_min, v_max = max(0, v.min()-v_pad), min(255, v.max()+v_pad)
    return [ ( (h_min,s_min,v_min), (h_max,s_max,v_max) ) ]

def main():
    if IFACE:
        ChannelFactoryInitialize(0, IFACE)
    else:
        ChannelFactoryInitialize(0)
    if CUSTOM_HSV_RANGES is not None:
        hsv_ranges = CUSTOM_HSV_RANGES
    else:
        hsv_ranges = COLOR_PRESETS.get(PRESET, COLOR_PRESETS['red'])
    print('[INFO] HSV ranges:', hsv_ranges)
    sc = SportClient(); sc.SetTimeout(5); sc.Init(); sc.StandUp(); time.sleep(2)
    try: sc.BalanceStand(); time.sleep(0.4)
    except: pass
    try: sc.SpeedLevel(1)
    except: pass
    vc = VideoClient(); vc.SetTimeout(3.0); vc.Init()
    code, data = vc.GetImageSample()
    if code != 0:
        print('[ERROR] initial GetImageSample code=', code); return
    if not NO_DISPLAY:
        cv2.namedWindow('color_track', cv2.WINDOW_NORMAL)
    frame_idx=0; last_detection_time=0.0; consec_detect=0; tracking_active=False; last_target_cx=None
    cmd_period = 1.0/COMMAND_HZ; last_cmd_send=0.0; target_interval=1.0/MAX_FPS
    scan_dir=1; scan_switch_interval=6.0; last_scan_switch=time.time()
    try:
        while True:
            loop_start=time.time()
            code,data=vc.GetImageSample()
            if code!=0: break
            arr=np.frombuffer(bytes(data),dtype=np.uint8)
            frame_full=cv2.imdecode(arr,cv2.IMREAD_COLOR)
            if frame_full is None: continue
            frame_disp=frame_full; frame_proc=frame_full
            if SCALE!=1.0:
                frame_disp=cv2.resize(frame_full,(0,0),fx=SCALE,fy=SCALE,interpolation=cv2.INTER_AREA)
                if RESIZE_DETECT: frame_proc=frame_disp
            if BLUR>1 and BLUR%2==1:
                frame_blur=cv2.GaussianBlur(frame_proc,(BLUR,BLUR),0)
            else:
                frame_blur=frame_proc
            hsv=cv2.cvtColor(frame_blur,cv2.COLOR_BGR2HSV)
            mask=build_mask(hsv,hsv_ranges)
            if ERODE_ITERS>0: mask=cv2.erode(mask,None,iterations=ERODE_ITERS)
            if DILATE_ITERS>0: mask=cv2.dilate(mask,None,iterations=DILATE_ITERS)
            contours,_=cv2.findContours(mask,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
            best=None
            for c in contours:
                area=cv2.contourArea(c)
                if area<MIN_AREA: continue
                x,y,w,h=cv2.boundingRect(c)
                if best is None or area>best[0]: best=(area,(x,y,x+w,y+h))
            if best:
                last_detection_time=time.time(); consec_detect+=1
                if not tracking_active and consec_detect>=ACQUIRE_FRAMES: tracking_active=True
            else:
                if (time.time()-last_detection_time)>HOLD_TIME: consec_detect=0
            yaw_cmd=0.0; vx_cmd=0.0; tracking=False; disp_w=frame_disp.shape[1]
            if best:
                x1,y1,x2,y2=best[1]
                if (frame_proc is frame_full) and (frame_disp is not frame_full):
                    sx=frame_disp.shape[1]/frame_full.shape[1]; sy=frame_disp.shape[0]/frame_full.shape[0]
                    x1,y1,x2,y2=int(x1*sx),int(y1*sy),int(x2*sx),int(y2*sy)
                cx=(x1+x2)/2.0; last_target_cx=cx; error_px=cx-disp_w/2.0
                box_w=(x2-x1); width_frac=box_w/disp_w
                if tracking_active:
                    if abs(error_px)>DEADBAND_PX:
                        norm_err=error_px/(disp_w/2.0)
                        yaw_cmd=max(-MAX_YAW,min(MAX_YAW,-KP*norm_err))
                    tracking=True
                    if ENABLE_DISTANCE_CTRL:
                        dist_err=width_frac-TARGET_WIDTH_FRAC
                        if abs(dist_err)>VX_DEADBAND:
                            raw_vx=-KP_DIST*dist_err
                            if APPROACH_ONLY and raw_vx<0: raw_vx=0.0
                            vx_cmd=max(-MAX_VX,min(MAX_VX,raw_vx))
                if not NO_DISPLAY:
                    cv2.rectangle(frame_disp,(x1,y1),(x2,y2),(0,0,255),2)
                    cv2.line(frame_disp,(disp_w//2,0),(disp_w//2,frame_disp.shape[0]),(255,255,0),1)
                    cv2.circle(frame_disp,(int(cx),int((y1+y2)/2.0)),4,(0,255,255),-1)
                    if ENABLE_DISTANCE_CTRL:
                        cv2.putText(frame_disp,f'w%:{width_frac*100:.1f}',(10,40),cv2.FONT_HERSHEY_SIMPLEX,0.55,(0,200,255),1,cv2.LINE_AA)
            else:
                if tracking_active and (time.time()-last_detection_time)<=HOLD_TIME and last_target_cx is not None:
                    error_px=last_target_cx-disp_w/2.0
                    if abs(error_px)>DEADBAND_PX:
                        norm_err=error_px/(disp_w/2.0)
                        yaw_cmd=max(-MAX_YAW,min(MAX_YAW,-KP*norm_err))
                    tracking=True
                elif tracking_active and (time.time()-last_detection_time)>HOLD_TIME:
                    tracking_active=False
                if not tracking and (time.time()-last_detection_time)>=SCAN_TIMEOUT:
                    yaw_cmd=scan_dir*SCAN_YAW
                    if (time.time()-last_scan_switch)>=scan_switch_interval:
                        scan_dir*=-1; last_scan_switch=time.time()
            now=time.time()
            if now-last_cmd_send>=cmd_period:
                if ENABLE_DISTANCE_CTRL:
                    if 'prev_vx' not in locals(): prev_vx=0.0
                    smooth_vx=prev_vx+DIST_SMOOTH*(vx_cmd-prev_vx); prev_vx=smooth_vx
                else:
                    smooth_vx=0.0
                sc.Move(smooth_vx,0.0,yaw_cmd); last_cmd_send=now
            if not NO_DISPLAY:
                status='TRACK' if tracking else 'SCAN'
                extra=''
                if ENABLE_DISTANCE_CTRL:
                    extra=f' vx:{(prev_vx if "prev_vx" in locals() else 0):+.2f}'
                cv2.putText(frame_disp,f'{status} yaw:{yaw_cmd:+.2f}{extra}',(10,20),cv2.FONT_HERSHEY_SIMPLEX,0.6,(0,255,0) if tracking else (200,200,0),2,cv2.LINE_AA)
                cv2.imshow('color_track',frame_disp)
                key=cv2.waitKey(1)&0xFF
                if key in (27,ord('q')): break
                elif key==ord('s'):
                    fn=f'color_track_{int(time.time())}.png'; cv2.imwrite(fn,frame_disp); print('[INFO] saved',fn)
                elif key==ord('c'):
                    h,w=frame_proc.shape[:2]
                    patch=hsv[h//2-CAL_PATCH_HALF:h//2+CAL_PATCH_HALF,w//2-CAL_PATCH_HALF:w//2+CAL_PATCH_HALF]
                    hsv_ranges=auto_calibrate(patch,CAL_H_PAD,CAL_S_PAD,CAL_V_PAD)
                    print('[INFO] Recalibrated HSV ->',hsv_ranges)
            if DEBUG and frame_idx%30==0:
                print(f"[DBG] frame={frame_idx} trackActive={tracking_active} consec={consec_detect} yaw={yaw_cmd:.2f} vx={(prev_vx if 'prev_vx' in locals() else 0):.2f}")
            elapsed=time.time()-loop_start
            if elapsed<target_interval: time.sleep(target_interval-elapsed)
            frame_idx+=1
    except KeyboardInterrupt:
        print('KeyboardInterrupt - stopping')
    finally:
        try:
            sc.StopMove(); time.sleep(0.2); sc.StandDown(); time.sleep(1.0); sc.Damp()
        except: pass
        if not NO_DISPLAY: cv2.destroyAllWindows()
        print('Done.')

if __name__=='__main__':
    main()
