#!/usr/bin/env python3
"""Simple high-level sport state reader for Go2.
Prints selected fields from SportModeState at ~10 Hz.
Usage: python3 read_sport_state.py [iface]
If iface omitted, tries auto-detect (same logic as go2_sport_client.py).
"""
import sys, time, os, socket, fcntl, struct
from unitree_sdk2py.core.channel import ChannelSubscriber, ChannelFactoryInitialize
from unitree_sdk2py.idl.unitree_go.msg.dds_ import SportModeState_
from unitree_sdk2py.idl.default import unitree_go_msg_dds__SportModeState_

# Candidate topic names (try in order). We'll subscribe to the first that yields a valid sample.
SPORT_STATE_TOPICS = [
    "rt/sportmodestate",      # prefixed with rt/
    "sportmodestate",         # bare
    "rt/sportmode/state",     # path style
    "rt/highstate",           # legacy name in docs
    "highstate",              # bare legacy
]

def _list_interfaces():
    try:
        return [n for n in os.listdir('/sys/class/net') if os.path.isdir(os.path.join('/sys/class/net', n))]
    except Exception:
        return []

def _get_iface_ipv4(iface: str):
    SIOCGIFADDR = 0x8915
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    try:
        ifreq = struct.pack('256s', iface[:15].encode('utf-8'))
        res = fcntl.ioctl(sock.fileno(), SIOCGIFADDR, ifreq)
        ip = struct.unpack('!BBBB', res[20:24])
        return '.'.join(map(str, ip))
    except Exception:
        return None
    finally:
        sock.close()

def _auto_select_interface(preferred):
    interfaces = _list_interfaces()
    if preferred and preferred in interfaces:
        return preferred
    for iface in interfaces:
        ip = _get_iface_ipv4(iface)
        if ip and ip.startswith('192.168.123.'):
            return iface
    for iface in interfaces:
        if iface != 'lo':
            return iface
    return None

latest = unitree_go_msg_dds__SportModeState_()

if __name__ == '__main__':
    iface = sys.argv[1] if len(sys.argv) > 1 else None
    iface = _auto_select_interface(iface)
    print(f"[INFO] Using interface: {iface if iface else 'autodetermine'}")
    ChannelFactoryInitialize(0, iface) if iface else ChannelFactoryInitialize(0)

    subscribers = []
    for t in SPORT_STATE_TOPICS:
        try:
            s = ChannelSubscriber(t, SportModeState_)
            s.Init()
            subscribers.append((t, s))
        except Exception as e:
            print(f"[WARN] Failed to init subscriber for '{t}': {e}")
    if not subscribers:
        print("[ERROR] Could not create any subscribers. Exiting.")
        sys.exit(2)

    active_topic = None
    active_sub = None
    print("Probing topics for sport state...")
    try:
        while True:
            # Acquire active subscription if not yet locked.
            if active_sub is None:
                for t, s in subscribers:
                    probe = s.Read(0.01)
                    if probe:
                        active_topic = t
                        active_sub = s
                        print(f"[INFO] Locked onto topic '{t}'.")
                        sample = probe
                        break
                if active_sub is None:
                    time.sleep(0.05)
                    continue
            else:
                sample = active_sub.Read(0.1)

            if sample:
                try:
                    imu = getattr(sample, 'imu_state', None)
                    stamp = getattr(sample, 'stamp', None)
                    vx = sample.velocity[0] if hasattr(sample, 'velocity') else 0.0
                    vy = sample.velocity[1] if hasattr(sample, 'velocity') else 0.0
                    yaw_rate = sample.velocity[2] if hasattr(sample, 'velocity') else 0.0
                    if stamp and hasattr(stamp, 'sec'):
                        tstr = f"{stamp.sec}.{getattr(stamp,'nsec',0):09d}"
                    else:
                        tstr = "-"
                    if imu and hasattr(imu, 'rpy'):
                        rpy = f"({imu.rpy[0]:.2f},{imu.rpy[1]:.2f},{imu.rpy[2]:.2f})"
                    else:
                        rpy = "(?, ?, ?)"
                    print(f"t={tstr} mode={getattr(sample,'mode','?')} vel=({vx:.2f},{vy:.2f},{yaw_rate:.2f}) imu_rpy={rpy} topic={active_topic}")
                except Exception as e:
                    print("[WARN] Could not parse sample:", e)

            time.sleep(0.1)
    except KeyboardInterrupt:
        pass
    print("Done.")
