#!/usr/bin/env python3
"""YOLOv8 Object Detection Stream for Unitree Go2 Front Camera

Requirements:
  pip install ultralytics opencv-python numpy
  (Optionally) pip install torch torchvision --index-url https://download.pytorch.org/whl/cu121  # if you want CUDA

Usage:
  python3 camera_yolo.py [iface] [--model yolov8n.pt] [--conf 0.25] [--scale 0.75] \
      [--max-fps 30] [--detect-interval 1] [--save out.mp4] [--show-fps]

Keys:
  q / ESC : quit
  s       : save current annotated frame PNG
  p       : pause/resume detection (video still displayed)

Notes:
  - Uses the same VideoClient API (request-response frame pulling).
  - Detection can be throttled with --detect-interval (run detector every N frames).
  - Frames between detections reuse last detections to reduce load.
  - Automatically rescales display (not affecting original resolution used for detection unless scale<1 and --resize-detect is given).
"""
import sys, time, os, argparse, math
import cv2
import numpy as np
from unitree_sdk2py.core.channel import ChannelFactoryInitialize
from unitree_sdk2py.go2.video.video_client import VideoClient

try:
    from ultralytics import YOLO
except ImportError:
    YOLO = None


def parse_args():
    p = argparse.ArgumentParser()
    p.add_argument('iface', nargs='?', default=None, help='Network interface (e.g. enp3s0)')
    p.add_argument('--model', default='yolov8n.pt', help='YOLOv8 model path/name (e.g., yolov8n.pt)')
    p.add_argument('--conf', type=float, default=0.25, help='Confidence threshold')
    p.add_argument('--iou', type=float, default=0.45, help='IoU threshold (for NMS)')
    p.add_argument('--scale', type=float, default=1.0, help='Display scale factor (e.g. 0.5)')
    p.add_argument('--resize-detect', action='store_true', help='Run detection on scaled frame instead of full-res')
    p.add_argument('--max-fps', type=int, default=30, help='Frame acquisition FPS cap')
    p.add_argument('--detect-interval', type=int, default=1, help='Run detection every N frames (>=1)')
    p.add_argument('--save', dest='save_path', default=None, help='Save annotated video to file')
    p.add_argument('--show-fps', action='store_true', help='Show FPS overlay text')
    p.add_argument('--no-labels', action='store_true', help='Do not draw text labels (only boxes)')
    p.add_argument('--line-thickness', type=int, default=2, help='Box line thickness')
    return p.parse_args()


def create_writer(path, w, h, fps):
    if not path:
        return None
    ext = os.path.splitext(path)[1].lower()
    if ext == '':
        path += '.mp4'
        ext = '.mp4'
    # Try a few fourccs
    fourccs = ['mp4v', 'avc1', 'H264', 'MJPG'] if ext in ('.mp4', '.m4v') else ['MJPG', 'XVID', 'mp4v']
    for f in fourccs:
        try:
            wri = cv2.VideoWriter(path, cv2.VideoWriter_fourcc(*f), fps, (w, h))
            if wri.isOpened():
                print(f"[INFO] Video writer open ({f}) -> {path}")
                return wri
        except Exception:
            pass
    print('[WARN] Could not create writer; continuing without save.')
    return None


def load_model(path):
    if YOLO is None:
        print('[ERROR] ultralytics not installed. Run: pip install ultralytics')
        sys.exit(2)
    try:
        model = YOLO(path)
        return model
    except Exception as e:
        print('[ERROR] Failed to load model:', e)
        sys.exit(2)


def annotate(frame, dets, class_names, show_labels=True, thickness=2):
    if dets is None:
        return frame
    h, w = frame.shape[:2]
    for *box, conf, cls in dets:
        x1, y1, x2, y2 = map(int, box)
        conf_f = float(conf)
        cls_id = int(cls)
        color = (0, 255, 0)
        cv2.rectangle(frame, (x1, y1), (x2, y2), color, thickness)
        if show_labels:
            label = f"{class_names[cls_id] if cls_id < len(class_names) else cls_id}:{conf_f:.2f}"
            (tw, th), bl = cv2.getTextSize(label, cv2.FONT_HERSHEY_SIMPLEX, 0.45, 1)
            cv2.rectangle(frame, (x1, y1 - th - 4), (x1 + tw + 4, y1), color, -1)
            cv2.putText(frame, label, (x1 + 2, y1 - 4), cv2.FONT_HERSHEY_SIMPLEX, 0.45, (0,0,0), 1, cv2.LINE_AA)
    return frame


def main():
    args = parse_args()
    if args.iface:
        ChannelFactoryInitialize(0, args.iface)
    else:
        ChannelFactoryInitialize(0)

    model = load_model(args.model)
    names = model.names if hasattr(model, 'names') else []

    vc = VideoClient(); vc.SetTimeout(3.0); vc.Init()
    code, data = vc.GetImageSample()
    if code != 0:
        print('[ERROR] Initial GetImageSample failed code=', code)
        return

    cv2.namedWindow('go2_yolo', cv2.WINDOW_NORMAL)

    frame_idx = 0
    last_det = None
    last_det_frame = -1
    last_fps_t = time.time()
    frame_counter = 0
    fps = 0.0
    target_interval = 1.0 / max(1, args.max_fps)
    writer = None
    paused = False

    while code == 0:
        loop_start = time.time()
        if not paused:
            code, data = vc.GetImageSample()
            if code != 0:
                print('[INFO] End of stream or error code=', code)
                break
            img_buf = np.frombuffer(bytes(data), dtype=np.uint8)
            frame_full = cv2.imdecode(img_buf, cv2.IMREAD_COLOR)
            if frame_full is None:
                print('[WARN] decode failure')
                continue
        else:
            # If paused, just wait a bit and continue displaying last annotated frame
            time.sleep(0.05)
            key = cv2.waitKey(1) & 0xFF
            if key in (27, ord('q')):
                break
            elif key == ord('p'):
                paused = False
            continue

        frame_for_detect = frame_full
        if args.scale != 1.0:
            frame_disp = cv2.resize(frame_full, (0,0), fx=args.scale, fy=args.scale, interpolation=cv2.INTER_AREA)
            if args.resize_detect:
                frame_for_detect = frame_disp
        else:
            frame_disp = frame_full

        run_det = (frame_idx - last_det_frame) >= args.detect_interval
        dets_xyxy = None
        if run_det:
            # YOLO expects RGB
            rgb = cv2.cvtColor(frame_for_detect, cv2.COLOR_BGR2RGB)
            # Results list; use .boxes.xyxy etc.
            results = model.predict(rgb, conf=args.conf, iou=args.iou, verbose=False)
            if results:
                r0 = results[0]
                if r0.boxes is not None and len(r0.boxes) > 0:
                    # xyxy, conf, cls
                    dets_xyxy = []
                    for b in r0.boxes:
                        xyxy = b.xyxy[0].tolist()
                        conf = b.conf[0].item()
                        cls = b.cls[0].item()
                        dets_xyxy.append(xyxy + [conf, cls])
                last_det = dets_xyxy
                last_det_frame = frame_idx
        else:
            dets_xyxy = last_det

        # If detection ran on scaled frame but we display scaled frame, OK.
        # If detection ran on full-res but display is scaled, we need to scale boxes.
        if dets_xyxy and (frame_for_detect is frame_full) and (frame_disp is not frame_full):
            scale_x = frame_disp.shape[1] / frame_full.shape[1]
            scale_y = frame_disp.shape[0] / frame_full.shape[0]
            adj = []
            for d in dets_xyxy:
                x1,y1,x2,y2,conf,cls = d
                adj.append([x1*scale_x, y1*scale_y, x2*scale_x, y2*scale_y, conf, cls])
            dets_to_draw = adj
        else:
            dets_to_draw = dets_xyxy

        annotate(frame_disp, dets_to_draw, names, show_labels=not args.no_labels, thickness=args.line_thickness)

        frame_counter += 1
        now = time.time()
        if now - last_fps_t >= 1.0:
            fps = frame_counter / (now - last_fps_t)
            frame_counter = 0
            last_fps_t = now

        title = f"Go2 YOLO {frame_disp.shape[1]}x{frame_disp.shape[0]} fps:{fps:.1f} detInt:{args.detect_interval}"
        cv2.imshow('go2_yolo', frame_disp)
        cv2.setWindowTitle('go2_yolo', title)

        if writer is None and args.save_path:
            oh, ow = frame_disp.shape[:2]
            writer = create_writer(args.save_path, ow, oh, min(args.max_fps, 30))
        if writer is not None:
            writer.write(frame_disp)

        key = cv2.waitKey(1) & 0xFF
        if key in (27, ord('q')):
            break
        elif key == ord('s'):
            fname = f"yolo_frame_{int(time.time())}.png"
            cv2.imwrite(fname, frame_disp)
            print('[INFO] saved', fname)
        elif key == ord('p'):
            paused = True

        frame_idx += 1
        # Throttle
        elapsed = time.time() - loop_start
        to_sleep = target_interval - elapsed
        if to_sleep > 0:
            time.sleep(to_sleep)

    if writer is not None:
        writer.release()
    cv2.destroyAllWindows()
    print('Done.')

if __name__ == '__main__':
    main()
