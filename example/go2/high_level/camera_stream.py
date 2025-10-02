#!/usr/bin/env python3
"""Continuous front camera streaming helper.

Usage:
  python3 camera_stream.py [iface] [--save video.mp4] [--max-fps 20]

Features:
  - Auto init DDS (optionally with interface argument)
  - Pulls frames using VideoClient.GetImageSample()
  - Shows live FPS & resolution in window title
  - Optional MP4 saving (H.264 if available, else fallback to MJPG)
  - Press:  q or ESC  -> quit
             s        -> save current frame as PNG (timestamped)
"""
import sys, time, os, cv2, numpy as np, argparse
from unitree_sdk2py.core.channel import ChannelFactoryInitialize
from unitree_sdk2py.go2.video.video_client import VideoClient


def parse_args():
    p = argparse.ArgumentParser()
    p.add_argument('iface', nargs='?', default=None, help='Network interface (e.g., enp3s0)')
    p.add_argument('--save', dest='save_path', default=None, help='Optional output video file (.mp4/.avi)')
    p.add_argument('--max-fps', type=int, default=30, help='Frame throttle (pull loop)')
    p.add_argument('--scale', type=float, default=1.0, help='Scale factor for display (e.g. 0.5 = half size)')
    return p.parse_args()


def create_writer(path, w, h, fps):
    if path is None:
        return None
    fourccs = [('mp4v','mp4'), ('avc1','mp4'), ('H264','mp4'), ('MJPG','avi')]
    ext = os.path.splitext(path)[1].lower()
    if ext == '':
        path = path + '.mp4'
    for fourcc, prefer_ext in fourccs:
        if ext == '' or ext[1:] == prefer_ext:
            try:
                writer = cv2.VideoWriter(path, cv2.VideoWriter_fourcc(*fourcc), fps, (w,h))
                if writer.isOpened():
                    print(f"[INFO] Video writer using {fourcc} -> {path}")
                    return writer
            except Exception:
                pass
    print('[WARN] Failed to create video writer; continuing without save.')
    return None


def main():
    args = parse_args()
    if args.iface:
        ChannelFactoryInitialize(0, args.iface)
    else:
        ChannelFactoryInitialize(0)

    client = VideoClient()
    client.SetTimeout(3.0)
    client.Init()

    code, data = client.GetImageSample()
    if code != 0:
        print('Initial GetImageSample failed code=', code)
        return

    last_t = time.time()
    frame_count = 0
    fps = 0.0
    writer = None
    target_interval = 1.0 / max(1, args.max_fps)

    # Prepare window (allow user resize)
    cv2.namedWindow('go2_front_camera', cv2.WINDOW_NORMAL)
    while code == 0:
        start_pull = time.time()
        code, data = client.GetImageSample()
        if code != 0:
            print('GetImageSample error code=', code)
            break
        image_data = np.frombuffer(bytes(data), dtype=np.uint8)
        frame = cv2.imdecode(image_data, cv2.IMREAD_COLOR)
        if frame is None:
            print('[WARN] decode returned None')
            continue
        # Optional scaling for display
        if args.scale != 1.0:
            frame_disp = cv2.resize(frame, (0,0), fx=args.scale, fy=args.scale, interpolation=cv2.INTER_AREA)
        else:
            frame_disp = frame
        h, w = frame_disp.shape[:2]
        frame_count += 1
        now = time.time()
        if now - last_t >= 1.0:
            fps = frame_count / (now - last_t)
            frame_count = 0
            last_t = now

        title = f'Go2 Front Camera {w}x{h} FPS:{fps:.1f} scale={args.scale}'
        cv2.imshow('go2_front_camera', frame_disp)
        cv2.setWindowTitle('go2_front_camera', title)

        if writer is None and args.save_path:
            # Always record original resolution, not scaled
            oh, ow = frame.shape[:2]
            writer = create_writer(args.save_path, ow, oh, min(args.max_fps, 30))
        if writer is not None:
            writer.write(frame)

        key = cv2.waitKey(1) & 0xFF
        if key in (27, ord('q')):
            break
        elif key == ord('s'):
            fname = f'frame_{int(time.time())}.png'
            # Save original resolution frame
            cv2.imwrite(fname, frame)
            print('[INFO] saved', fname)

        # Throttle
        elapsed = time.time() - start_pull
        if elapsed < target_interval:
            time.sleep(target_interval - elapsed)

    if writer is not None:
        writer.release()
    cv2.destroyAllWindows()
    print('Done.')

if __name__ == '__main__':
    main()
