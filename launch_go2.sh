#!/bin/bash
# Go2 Robot ROS2 Launcher Script 
# Author: Hudson Trice
# Usage: ./launch_go2.sh

set -e  # Exit on any error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m'

echo -e "${GREEN}=== Unitree Go2 ROS2 Launcher ===${NC}"

# Check workspace
if [ ! -d "src/go2_robot_sdk" ] || [ ! -d "install" ]; then
    echo -e "${RED}ERROR:${NC} Run from workspace root with built packages"
    exit 1
fi

# Get robot IP - prompt for last two digits
read -p "Robot IP 192.168.X.X (enter last two numbers, e.g., 1.7): " ip_suffix
ip_suffix=${ip_suffix:-1.7}
robot_ip="192.168.${ip_suffix}"

# Test connection - MUST succeed
echo -e "${BLUE}Testing connection to $robot_ip...${NC}"
if ! ping -c 2 -W 3 "$robot_ip" > /dev/null 2>&1; then
    echo -e "${RED}ERROR:${NC} Cannot reach robot at $robot_ip"
    echo "- Check robot is powered on"
    echo "- Check Wi-Fi connection"
    echo "- Verify IP in Unitree app"
    echo "- Ensure Unitree mobile app is closed if using WebRTC, only one connection allowed"
    exit 1
fi
echo -e "${GREEN}✓ Robot reachable${NC}"

# Connection type
echo "Connection: [1] WebRTC (default) [2] CycloneDDS"
read -p "Choice [1]: " conn_choice
conn_choice=${conn_choice:-1}

if [ "$conn_choice" = "2" ]; then
    conn_type="cyclonedx"
    export RMW_IMPLEMENTATION=rmw_cyclonedx_cpp
else
    conn_type="webrtc"
    echo -e "${BLUE}Close Unitree mobile app${NC}"
fi

# Launch options
echo -e "${BLUE}Launch options:${NC}"
echo "  [1] Basic      - Core robot functionality only"
echo "  [2] +Foxglove  - Adds Foxglove web visualization support"
echo "  [3] +Detection - Adds object detection capabilities"
echo "  [4] Full       - Complete setup with Foxglove and detection"
echo ""
echo "Launch: [1] Basic [2] +Foxglove [3] +Detection [4] Full"
read -p "Choice [2]: " launch_choice
launch_choice=${launch_choice:-2}

# Set up environment
source /opt/ros/humble/setup.bash
source install/setup.bash
export ROBOT_IP="$robot_ip"
export CONN_TYPE="$conn_type"

# Build launch command
launch_cmd="ros2 launch go2_robot_sdk robot.launch.py rviz2:=false"

case $launch_choice in
    2|4) launch_cmd="$launch_cmd foxglove:=true" ;;
esac

if [ "$launch_choice" = "2" ] || [ "$launch_choice" = "4" ]; then
    echo -e "${GREEN}Video: https://studio.foxglove.dev/ → ws://localhost:8765${NC}"
fi

echo -e "${GREEN}Launching...${NC}"
echo "Press Ctrl+C to stop"

# Launch
if [ "$launch_choice" = "3" ] || [ "$launch_choice" = "4" ]; then
    $launch_cmd &
    sleep 8
    ros2 run coco_detector coco_detector_node &
    wait
else
    exec $launch_cmd
fi
