#!/usr/bin/env python3
"""Ultra-basic color tracking: turn to face a colored blob.
Steps:
 1. Get frame
 2. BGR -> HSV
 3. Threshold to binary mask
 4. Largest contour = target
 5. Yaw toward its center
Press q or ESC to quit.
Change LOWER_HSV / UPPER_HSV below for different colors."""

import time, numpy as np, cv2
from unitree_sdk2py.core.channel import ChannelFactoryInitialize
from unitree_sdk2py.go2.sport.sport_client import SportClient
from unitree_sdk2py.go2.video.video_client import VideoClient
from collections import deque

IFACE = "enp3s0"          # network interface (or None)

# Choose a color name below OR set COLOR = 'custom' and edit CUSTOM_LOWER / CUSTOM_UPPER
COLOR = "blue"             # e.g. blue, red, green, yellow, orange, purple, pink, custom

COLOR_PRESETS = {
    # Hue ranges are approximate; lighting matters. Start broad, narrow later.
    'blue':   ((100,120,60), (130,255,255)),
    'red':    ((0,100,70),   (10,255,255)),
    'green':  ((35,60,60),   (85,255,255)),
    'yellow': ((20,110,110), (32,255,255)),
    'orange': ((10,130,120), (22,255,255)),
    'purple': ((130,80,60),  (155,255,255)),
    'pink':   ((150,60,120), (170,255,255)),
}

# Used only if COLOR == 'custom'
CUSTOM_LOWER = (100,120,60)
CUSTOM_UPPER = (130,255,255)

if COLOR == 'blue':
    LOWER_HSV, UPPER_HSV = CUSTOM_LOWER, CUSTOM_UPPER
else:
    if COLOR not in COLOR_PRESETS:
        raise ValueError(f"Unknown COLOR '{COLOR}'. Valid: {list(COLOR_PRESETS.keys())} or 'custom'")
    LOWER_HSV, UPPER_HSV = COLOR_PRESETS[COLOR]

# TURNING VARIABLES
KP = 0.9                    # turn speed gain
MAX_YAW = 0.8               # yaw speed limit
DEADBAND_PX = 40            # ignore tiny errors
COMMAND_HZ = 20.0           # command send rate
MIN_AREA = 1500             # smallest blob to accept
FMR = 0.3                   # forward move rate

#MOVEMENT VARIABLES
TARGET_WIDTH_FRACT = 0.35    # desired fraction of the image width for blob
KP_DIST = 1.2               # proportional gain for forward/back control
MAX_VX = 0.3                # max forward / backwards speed (m/s)
VX_DEADBAND= 0.02           # ignore small errors


SMOOTH_WINDOW = 5           # Number of frames to average to smooth out the movement
def main():
    # 1. Init robot communication
    if IFACE:
        ChannelFactoryInitialize(0, IFACE)
    else:
        ChannelFactoryInitialize(0)

    # 2. Init movement + camera clients
    sport = SportClient(); sport.SetTimeout(5); sport.Init()
    print("Standing up..."); sport.StandUp(); time.sleep(2)
    try: sport.BalanceStand(); time.sleep(0.3)
    except: pass

    video = VideoClient(); video.SetTimeout(3.0); video.Init()
    code, data = video.GetImageSample()
    if code != 0:
        print("Camera error", code); return

    cv2.namedWindow("track", cv2.WINDOW_NORMAL)

    last_cmd_time = 0.0
    cmd_period = 1.0 / COMMAND_HZ

    yaw_buffer = deque(maxlen=SMOOTH_WINDOW)
    vx_buffer = deque(maxlen=SMOOTH_WINDOW)

    try:
        while True:
            # 3. Grab frame bytes and decode JPEG
            code, data = video.GetImageSample()
            if code != 0:
                print("Camera stream ended", code)
                break
            arr = np.frombuffer(bytes(data), dtype=np.uint8)
            frame = cv2.imdecode(arr, cv2.IMREAD_COLOR)
            if frame is None:
                continue

            frame_disp = frame  # no scaling to keep simple
            # 4. Convert to HSV & threshold
            hsv = cv2.cvtColor(frame_disp, cv2.COLOR_BGR2HSV)
            lower = np.array(LOWER_HSV, dtype=np.uint8)
            upper = np.array(UPPER_HSV, dtype=np.uint8)
            mask = cv2.inRange(hsv, lower, upper)

            # 5. Find biggest contour (blob)
            contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
            best = None
            for c in contours:
                area = cv2.contourArea(c)
                if area < MIN_AREA:
                    continue
                x,y,w,h = cv2.boundingRect(c)
                if best is None or area > best[0]:
                    best = (area, (x,y,w,h))

            width = frame_disp.shape[1]
            center_x = width / 2.0
            yaw_cmd = 0.0
            forward_cmd = 0.0
            status = "SCAN"

            if best:
                status = "TRACK"
                area, (x,y,w,h) = best
                blob_cx = x + w/2.0
                error_px = blob_cx - center_x  # + if blob is to the right

                # Yaw control
                if abs(error_px) > DEADBAND_PX:
                    norm_err = error_px / (width / 2.0)
                    yaw_cmd = -KP * norm_err
                    yaw_cmd = max(-MAX_YAW, min(MAX_YAW, yaw_cmd))

                # Forward/backward control (proportional)
                blob_width_frac = w / width
                dist_err = blob_width_frac - TARGET_WIDTH_FRACT
                if abs(dist_err) > VX_DEADBAND:
                    raw_vx = -KP_DIST * dist_err
                    forward_cmd = max(-MAX_VX, min(MAX_VX, raw_vx))
                else:
                    forward_cmd = 0.0

                # Draw visuals
                cv2.rectangle(frame_disp, (x,y), (x+w,y+h), (0,0,255), 2)
                cv2.circle(frame_disp, (int(blob_cx), int(y+h/2)), 4, (0,255,255), -1)
                cv2.line(frame_disp, (int(center_x),0), (int(center_x), frame_disp.shape[0]), (255,255,0),1)

            # 5. Smoothing
            yaw_buffer.append(yaw_cmd)
            vx_buffer.append(forward_cmd)
            smoothed_yaw = sum(yaw_buffer) / len(yaw_buffer)
            smoothed_vx = sum(vx_buffer) / len(vx_buffer)

            # 6. Send motion command at fixed rate
            now = time.time()
            if now - last_cmd_time >= cmd_period:
                sport.Move(smoothed_vx, 0.0, smoothed_yaw)
                last_cmd_time = now

            cv2.putText(frame_disp, f"{status} yaw:{yaw_cmd:+.2f}", (10,20), cv2.FONT_HERSHEY_SIMPLEX, 0.6,
                        (0,255,0) if status=="TRACK" else (0,200,200), 2, cv2.LINE_AA)
            cv2.imshow("track", frame_disp)
            key = cv2.waitKey(1) & 0xFF
            if key in (27, ord('q')):
                print("Exit key pressed")
                break

    except KeyboardInterrupt:
        print("Ctrl+C detected")
    finally:
        # Stop + relax robot safely
        try:
            sport.StopMove(); time.sleep(0.2)
            sport.StandDown(); time.sleep(1.0)
            sport.Damp()
        except Exception:
            pass
    cv2.destroyAllWindows()
    print("Done.")

if __name__ == "__main__":
    main()