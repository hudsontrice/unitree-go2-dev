import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/htrice/go2_ros2_curr/install/go2_robot_sdk'
