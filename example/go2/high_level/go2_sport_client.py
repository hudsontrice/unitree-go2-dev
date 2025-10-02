import time
import sys
import os
import socket
import fcntl
import struct
from unitree_sdk2py.core.channel import ChannelSubscriber, ChannelFactoryInitialize
from unitree_sdk2py.idl.default import unitree_go_msg_dds__SportModeState_
from unitree_sdk2py.idl.unitree_go.msg.dds_ import SportModeState_
from unitree_sdk2py.go2.sport.sport_client import (
    SportClient,
    PathPoint,
    SPORT_PATH_POINT_SIZE,
)
import math
from dataclasses import dataclass

@dataclass
class TestOption:
    name: str
    id: int

option_list = [
    TestOption(name="damp", id=0),         
    TestOption(name="stand_up", id=1),     
    TestOption(name="stand_down", id=2),   
    TestOption(name="move forward", id=3),         
    TestOption(name="move lateral", id=4),    
    TestOption(name="move rotate", id=5),  
    TestOption(name="stop_move", id=6),  
    TestOption(name="hand stand", id=7),
    TestOption(name="balanced stand", id=9),     
    TestOption(name="recovery", id=10),       
    TestOption(name="left flip", id=11),      
    TestOption(name="back flip", id=12),
    TestOption(name="free walk", id=13),  
    TestOption(name="free bound", id=14), 
    TestOption(name="free avoid", id=15),  
    TestOption(name="walk upright", id=17),
    TestOption(name="cross step", id=18),
    TestOption(name="free jump", id=19)       
]

class UserInterface:
    def __init__(self):
        self.test_option_ = None

    def convert_to_int(self, input_str):
        try:
            return int(input_str)
        except ValueError:
            return None

    def terminal_handle(self):
        input_str = input("Enter id or name: \n")

        if input_str == "list":
            self.test_option_.name = None
            self.test_option_.id = None
            for option in option_list:
                print(f"{option.name}, id: {option.id}")
            return

        for option in option_list:
            if input_str == option.name or self.convert_to_int(input_str) == option.id:
                self.test_option_.name = option.name
                self.test_option_.id = option.id
                print(f"Test: {self.test_option_.name}, test_id: {self.test_option_.id}")
                return

        print("No matching test option found.")

def _list_interfaces():
    try:
        return [n for n in os.listdir('/sys/class/net') if os.path.isdir(os.path.join('/sys/class/net', n))]
    except Exception:
        return []

def _get_iface_ipv4(iface: str):
    # Minimal ioctl based lookup to avoid extra deps
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

def _auto_select_interface(preferred: str | None):
    interfaces = _list_interfaces()
    # 1. If user supplied and exists, keep it
    if preferred and preferred in interfaces:
        return preferred, None
    reason = None
    if preferred and preferred not in interfaces:
        reason = f"Provided interface '{preferred}' not found."
    # 2. Try to find interface in 192.168.123.x (default Unitree subnet)
    for iface in interfaces:
        ip = _get_iface_ipv4(iface)
        if ip and ip.startswith('192.168.123.'):
            return iface, reason
    # 3. Fallback: first non-loopback
    for iface in interfaces:
        if iface != 'lo':
            return iface, reason
    # 4. Nothing usable; return None
    return None, reason

if __name__ == "__main__":

    print("WARNING: Please ensure there are no obstacles around the robot while running this example.")
    input("Press Enter to continue...")

    user_iface = sys.argv[1] if len(sys.argv) > 1 else None
    chosen_iface, warn = _auto_select_interface(user_iface)

    try:
        if chosen_iface:
            ChannelFactoryInitialize(0, chosen_iface)
            if warn:
                print(f"[INFO] {warn} Auto-selected '{chosen_iface}'.")
            else:
                print(f"[INFO] Using network interface '{chosen_iface}'.")
        else:
            print("[WARN] No suitable network interface found, attempting autodetermine mode (may fail).")
            ChannelFactoryInitialize(0)
    except Exception as e:
        interfaces = _list_interfaces()
        print("[ERROR] DDS channel initialization failed:", e)
        print("[HINT] Available interfaces:", ', '.join(interfaces) if interfaces else 'NONE')
        print("        If your robot is on a specific NIC, re-run: python3 go2_sport_client.py <iface>")
        sys.exit(1)

    test_option = TestOption(name=None, id=None) 
    user_interface = UserInterface()
    user_interface.test_option_ = test_option

    sport_client = SportClient()  
    sport_client.SetTimeout(10.0)
    sport_client.Init()
    while True:

        user_interface.terminal_handle()

        print(f"Updated Test Option: Name = {test_option.name}, ID = {test_option.id}\n")

        if test_option.id == 0:
            sport_client.Damp()
        elif test_option.id == 1:
            sport_client.StandUp()
        elif test_option.id == 2:
            sport_client.StandDown()
        elif test_option.id == 3:
            ret = sport_client.Move(0.3,0,0)
            print("ret: ",ret)
        elif test_option.id == 4:
            sport_client.Move(0,0.3,0)
        elif test_option.id == 5:
            sport_client.Move(0,0,0.5)
        elif test_option.id == 6:
            sport_client.StopMove()
        elif test_option.id == 7:
            sport_client.HandStand(True)
            time.sleep(4)
            sport_client.HandStand(False)
        elif test_option.id == 9:
            sport_client.BalanceStand()
        elif test_option.id == 10:
            sport_client.RecoveryStand()
        elif test_option.id == 11:
            ret = sport_client.LeftFlip()
            print("ret: ",ret)
        elif test_option.id == 12:
            ret = sport_client.BackFlip()
            print("ret: ",ret)
        elif test_option.id == 13:
            ret = sport_client.FreeWalk()
            print("ret: ",ret)
        elif test_option.id == 14:
            ret = sport_client.FreeBound(True)
            print("ret: ",ret)
            time.sleep(2)
            ret = sport_client.FreeBound(False)
            print("ret: ",ret)
        elif test_option.id == 15:
            ret = sport_client.FreeAvoid(True)
            print("ret: ",ret)
            time.sleep(2)
            ret = sport_client.FreeAvoid(False)
            print("ret: ",ret)
        elif test_option.id == 17:
            ret = sport_client.WalkUpright(True)
            print("ret: ",ret)
            time.sleep(4)
            ret = sport_client.WalkUpright(False)
            print("ret: ",ret)
        elif test_option.id == 18:
            ret = sport_client.CrossStep(True)
            print("ret: ",ret)
            time.sleep(4)
            ret = sport_client.CrossStep(False)
            print("ret: ",ret)
        elif test_option.id == 19:
            ret = sport_client.FreeJump(True)
            print("ret: ",ret)
            time.sleep(4)
            ret = sport_client.FreeJump(False)
            print("ret: ",ret)

        time.sleep(1)
