# Unitree Go2 ROS2 Development Workspace

A complete ROS 2 workspace for Unitree Go2 robot development with WebRTC connectivity, sensor integration, and visualization tools.

## Quick Start

### 1. Clone Repository
```bash
git clone https://github.com/hudsontrice/unitree-go2-dev.git
cd unitree-go2-dev
```

### 2. Build Workspace
Run the automated build script to install all dependencies and build the workspace:
```bash
./build_go2.sh
```

This script will:
- Install ROS 2 Humble (if not present)
- Install system dependencies
- Install Python requirements
- Build the ROS 2 workspace
- Set up environment variables

### 3. Launch Robot Connection
Use the interactive launch script to connect to your Go2 robot:
```bash
./launch_go2.sh
```

The launch script will:
- Prompt for robot IP address
- Test connectivity
- Offer connection type options (WebRTC/CycloneDDS)
- Launch with optional visualization tools

## Features

### Core Capabilities
- **WebRTC Connection**: Real-time video and data streaming
- **CycloneDDS Support**: Alternative communication protocol
- **Camera Integration**: HD video feed (1280x720)
- **LiDAR Processing**: 360° point cloud data
- **IMU & Odometry**: Robot state monitoring
- **Object Detection**: COCO-based detection (80 classes)

### Visualization Tools
- **Foxglove Studio**: Web-based visualization at `ws://localhost:8765`
- **RViz2**: Traditional ROS visualization
- **Real-time Data**: Live sensor feeds and robot state

### Navigation & SLAM
- **SLAM Toolbox**: Simultaneous localization and mapping
- **Nav2**: Navigation stack integration
- **Teleop**: Keyboard and joystick control

## Package Structure

```
src/
├── go2_robot_sdk/          # Main SDK package
├── go2_interfaces/         # Custom message definitions
├── coco_detector/          # Object detection
├── lidar_processor/        # LiDAR data processing
└── speech_processor/       # Audio processing
```

## Usage Examples

### Basic Robot Connection
```bash
# Start with default WebRTC connection
ROBOT_IP=192.168.1.7 CONN_TYPE=webrtc ros2 launch go2_robot_sdk robot.launch.py

# Launch with Foxglove visualization
ROBOT_IP=192.168.1.7 CONN_TYPE=webrtc ros2 launch go2_robot_sdk robot.launch.py foxglove:=true
```

### View Available Topics
```bash
ros2 topic list
```

Key topics:
- `/camera/image_raw` - Camera feed
- `/scan` - LiDAR data
- `/imu` - IMU data
- `/odom` - Odometry
- `/go2_states` - Robot state

### Monitor Camera Feed
```bash
ros2 topic echo /camera/image_raw
```

## Configuration

### Robot Network Setup
1. Ensure Go2 robot is connected to your network
2. Note the robot's IP address (usually 192.168.X.X)
3. Close the Unitree mobile app to free the WebRTC connection

### Environment Variables
- `ROBOT_IP`: Target robot IP address
- `CONN_TYPE`: Connection type (`webrtc` or `cyclonedx`)
- `ROBOT_ID`: Robot identifier for multi-robot setups

## Troubleshooting

### Build Issues
```bash
# Clean build
rm -rf build/ install/ log/
./build_go2.sh
```

### Connection Issues
```bash
# Test robot connectivity
ping 192.168.1.7

# Check ROS 2 topics
ros2 topic list

# Verify packages
ros2 pkg list | grep go2
```

### Common Solutions
- Ensure Unitree app is closed before WebRTC connection
- Check network connectivity to robot
- Verify Python dependencies are installed
- Source workspace after building: `source install/local_setup.bash`

## Development

### Adding New Features
1. Create new packages in `src/`
2. Update dependencies in `package.xml`
3. Rebuild workspace: `colcon build --symlink-install`

### Custom Launch Files
Launch files are located in `src/go2_robot_sdk/launch/`

## Dependencies

### System Requirements
- Ubuntu 22.04 (recommended)
- ROS 2 Humble
- Python 3.10+

### Key Python Packages
- aiortc==1.9.0 (WebRTC)
- torch/torchvision (Object detection)
- opencv-python (Computer vision)
- open3d (Point cloud processing)

## Contributing

1. Fork the repository
2. Create feature branch
3. Make changes
4. Test with real robot
5. Submit pull request

## License

See LICENSE file for details.

## Support

For issues and questions:
- Check troubleshooting section
- Review ROS 2 logs: `ros2 log`
- Verify robot connectivity
- Check package dependencies
