#!/usr/bin/env python3
"""Ultra-basic person tracking (faces the largest detected person).

Steps:
 1. Initialize robot + camera + YOLO model
 2. Grab frame, run YOLO every N frames
 3. Pick largest 'person' box
 4. Compute horizontal pixel error from image center
 5. Apply proportional yaw command (with deadband + clamp)
 6. Loop until q / ESC / Ctrl+C

Edit ONLY the constants in the CONFIG section to experiment.
See person_track_advanced.py for the full-feature version.
"""
import time, cv2, numpy as np  # time for timing, cv2 for vision, numpy for arrays
from unitree_sdk2py.core.channel import ChannelFactoryInitialize
from unitree_sdk2py.go2.sport.sport_client import SportClient
from unitree_sdk2py.go2.video.video_client import VideoClient
try:
    from ultralytics import YOLO
except ImportError:
    YOLO = None

# -------- CONFIG (change values) --------
IFACE = "enp3s0"          # network interface name (None will let SDK pick default)
MODEL = "yolov8n.pt"      # small YOLOv8 model (fast). You can swap to yolov8s.pt etc.
CONF_THRESHOLD = 0.25      # we keep detections above this confidence
DETECT_INTERVAL = 2        # run the neural net every 2 frames (skips one = faster)
KP = 0.9                   # proportional gain (higher => turns more aggressively)
MAX_YAW = 0.8              # maximum turn speed in radians/sec
DEADBAND_PX = 40           # if error smaller than this, do nothing (prevents twitching)
COMMAND_HZ = 30.0          # how many times per second we send Move commands
SCALE = 1.0                # resize factor for the frame (1.0 = original size)
MIN_BOX_AREA = 500         # ignore very small person boxes (noise / far objects)
# ----------------------------------------

def load_model(path):
    if YOLO is None:
        raise SystemExit("ultralytics not installed: pip install ultralytics")
    return YOLO(path)

def main():
    # Initialize the network (DDS) channel. The robot needs this before using clients.
    ChannelFactoryInitialize(0, IFACE) if IFACE else ChannelFactoryInitialize(0)

    # Load YOLO model once (costly). Returns object with .predict(...)
    model = load_model(MODEL)

    # Get class name list from model (so we know which index is 'person').
    names = model.names if hasattr(model,'names') else []
    # Build a set of class IDs whose label contains the word 'person'. Fallback to {0}.
    person_ids = {i for i,n in enumerate(names) if 'person' in str(n).lower()} or {0}

    # Create the high-level motion client (SportClient) for simple velocity commands.
    sport = SportClient(); sport.SetTimeout(5); sport.Init()
    print('StandUp...')
    sport.StandUp(); time.sleep(2)   # wait a bit for posture to stabilize
    try:
        sport.BalanceStand(); time.sleep(0.3)  # switch into balance mode if supported
    except Exception:
        pass  # not critical

    # Create the video client (front camera). Then grab one test frame to confirm.
    video = VideoClient(); video.SetTimeout(3.0); video.Init()
    code, data = video.GetImageSample()  # returns (status_code, jpeg_bytes)
    if code != 0:
        print('Camera error', code); return

    # Create an OpenCV window to visualize tracking.
    cv2.namedWindow('person_simple', cv2.WINDOW_NORMAL)

    # Timing helpers
    last_cmd_time = 0.0            # last time we sent a Move command
    cmd_period = 1.0 / COMMAND_HZ  # seconds between commands
    last_det_frame = -1            # frame index when we last ran YOLO
    frame_idx = 0                  # counts processed frames

    try:
        while True:
            # Get frame
            code, data = video.GetImageSample()  # fresh JPEG each loop
            if code != 0:
                print('Stream ended', code); break
            arr = np.frombuffer(bytes(data), dtype=np.uint8)
            frame = cv2.imdecode(arr, cv2.IMREAD_COLOR)  # decode JPEG -> BGR image
            if frame is None:
                continue
            frame_disp = frame if SCALE == 1.0 else cv2.resize(frame,(0,0),fx=SCALE,fy=SCALE)

            # Run detection only every DETECT_INTERVAL frames
            best = None
            if (frame_idx - last_det_frame) >= DETECT_INTERVAL:  # time to run YOLO again
                rgb = cv2.cvtColor(frame_disp, cv2.COLOR_BGR2RGB)  # model wants RGB
                results = model.predict(rgb, conf=CONF_THRESHOLD, verbose=False)  # run inference
                last_det_frame = frame_idx
                if results:                     # results is a list; we take first image's result
                    r0 = results[0]
                    if r0.boxes is not None:    # iterate all detected boxes
                        for b in r0.boxes:
                            cls = int(b.cls[0].item())          # class id
                            if cls not in person_ids: continue  # skip non-person
                            conf = float(b.conf[0].item())      # confidence score
                            if conf < CONF_THRESHOLD: continue
                            x1,y1,x2,y2 = b.xyxy[0].tolist()    # bounding box corners
                            area = (x2-x1)*(y2-y1)
                            if area < MIN_BOX_AREA: continue    # filter very small boxes
                            # keep the largest person so we focus on closest / most visible
                            if best is None or area > best[0]:
                                best = (area, (x1,y1,x2,y2,conf))

            # Compute yaw command
            yaw_cmd = 0.0                    # default: no turn
            status = 'SCAN'                 # label shown on screen
            W = frame_disp.shape[1]         # image width in pixels
            center_x = W/2.0                # horizontal center pixel
            if best:
                status = 'TRACK'            # we found a person to track
                area,(x1,y1,x2,y2,conf) = best
                cx = 0.5*(x1+x2)            # box center x
                error_px = cx - center_x    # + if box is to the right of image center
                if abs(error_px) > DEADBAND_PX:          # ignore tiny offset
                    norm_err = error_px / (W/2.0)        # scale error to range about [-1,1]
                    yaw_raw = -KP * norm_err             # negative so right-of-center -> turn right
                    # clamp to safety limits
                    yaw_cmd = max(-MAX_YAW, min(MAX_YAW, yaw_raw))
                cv2.rectangle(frame_disp,(int(x1),int(y1)),(int(x2),int(y2)),(0,0,255),2)
                cv2.circle(frame_disp,(int(cx),int(0.5*(y1+y2))),4,(0,255,255),-1)
                cv2.line(frame_disp,(int(center_x),0),(int(center_x),frame_disp.shape[0]),(255,255,0),1)

            # Send motion at fixed rate
            now = time.time()
            if now - last_cmd_time >= cmd_period:  # send at fixed rate only
                sport.Move(0.0,0.0,yaw_cmd)        # (vx, vy, yaw_rate)
                last_cmd_time = now

            # Draw status
            cv2.putText(frame_disp,f"{status} yaw:{yaw_cmd:+.2f}",(10,20),cv2.FONT_HERSHEY_SIMPLEX,0.6,(0,255,0) if status=='TRACK' else (0,200,200),2,cv2.LINE_AA)
            cv2.imshow('person_simple', frame_disp)
            key = cv2.waitKey(1) & 0xFF
            if key in (27, ord('q')):
                print('Exit key pressed')
                break

            frame_idx += 1   # advance frame counter

    except KeyboardInterrupt:
        print('Ctrl+C')
    finally:
        try:  # attempt safe shutdown sequence
            sport.StopMove(); time.sleep(0.2)
            sport.StandDown(); time.sleep(1.0)
            sport.Damp()
        except Exception:
            pass
        cv2.destroyAllWindows()
        print('Done.')

if __name__ == '__main__':
    main()
