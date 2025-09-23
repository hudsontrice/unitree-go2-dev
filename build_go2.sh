#!/bin/bash

# Unitree Go2 ROS2 Build Script
# Handles installation, dependencies, and building of the workspace

set -e  # Exit on any error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Function to print colored output
print_status() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

print_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Function to check if command exists
command_exists() {
    command -v "$1" >/dev/null 2>&1
}

echo "============================================"
echo "  Unitree Go2 ROS2 Workspace Build Script  "
echo "============================================"
echo

# Check if we're in the right directory
if [ ! -f "launch_go2.sh" ] || [ ! -d "src" ]; then
    print_error "Please run this script from the Go2 ROS2 workspace root directory"
    print_error "Expected files: launch_go2.sh, src/ directory"
    exit 1
fi

print_status "Starting build process for Unitree Go2 ROS2 workspace..."

# Step 1: Update system packages
print_status "Step 1: Updating system packages..."
sudo apt update

# Step 2: Install ROS 2 Humble if not already installed
if ! command_exists ros2; then
    print_status "Step 2: Installing ROS 2 Humble..."
    
    # Add ROS 2 apt repository
    sudo apt install -y software-properties-common
    sudo add-apt-repository universe -y
    
    # Add ROS 2 GPG key
    sudo apt update && sudo apt install -y curl
    sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key | sudo apt-key add -
    
    # Add repository
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
    
    sudo apt update
    sudo apt install -y ros-humble-desktop python3-colcon-common-extensions
    
    print_success "ROS 2 Humble installed successfully"
else
    print_success "ROS 2 already installed"
fi

# Step 3: Install additional ROS 2 packages
print_status "Step 3: Installing additional ROS 2 packages..."
sudo apt install -y \
    python3-rosdep \
    python3-colcon-common-extensions \
    ros-humble-foxglove-bridge \
    ros-humble-slam-toolbox \
    ros-humble-navigation2 \
    ros-humble-nav2-bringup \
    ros-humble-joint-state-publisher \
    ros-humble-robot-state-publisher \
    ros-humble-xacro \
    ros-humble-tf2-tools \
    ros-humble-rviz2

print_success "Additional ROS 2 packages installed"

# Step 4: Install system dependencies
print_status "Step 4: Installing system dependencies..."
sudo apt install -y \
    python3-pip \
    python3-venv \
    build-essential \
    cmake \
    git \
    wget \
    curl \
    ffmpeg \
    libavcodec-dev \
    libavformat-dev \
    libavutil-dev \
    libswscale-dev \
    portaudio19-dev \
    pulseaudio \
    alsa-utils

print_success "System dependencies installed"

# Step 5: Setup Python environment and install requirements
print_status "Step 5: Installing Python requirements..."

if [ -f "src/requirements.txt" ]; then
    pip3 install -r src/requirements.txt
    print_success "Python requirements installed from src/requirements.txt"
elif [ -f "requirements.txt" ]; then
    pip3 install -r requirements.txt
    print_success "Python requirements installed from requirements.txt"
else
    print_warning "No requirements.txt found, installing common packages..."
    pip3 install \
        aiortc==1.9.0 \
        aiohttp \
        torch \
        torchvision \
        open3d \
        numpy==1.26.4 \
        opencv-python \
        pycryptodome \
        pydub \
        wasmtime \
        paho-mqtt \
        python-dotenv
    print_success "Common Python packages installed"
fi

# Step 6: Initialize rosdep if needed
print_status "Step 6: Initializing rosdep..."
if [ ! -f "/etc/ros/rosdep/sources.list.d/20-default.list" ]; then
    sudo rosdep init
    print_success "rosdep initialized"
else
    print_success "rosdep already initialized"
fi

rosdep update
print_success "rosdep updated"

# Step 7: Install workspace dependencies
print_status "Step 7: Installing workspace dependencies with rosdep..."
source /opt/ros/humble/setup.bash
rosdep install --from-paths src --ignore-src -r -y

print_success "Workspace dependencies installed"

# Step 8: Build the workspace
print_status "Step 8: Building ROS 2 workspace..."
source /opt/ros/humble/setup.bash
colcon build --symlink-install

if [ $? -eq 0 ]; then
    print_success "Workspace built successfully!"
else
    print_error "Build failed! Check the error messages above."
    exit 1
fi

# Step 9: Set up environment
print_status "Step 9: Setting up environment..."

# Add to bashrc if not already present
BASHRC_LINE="source /opt/ros/humble/setup.bash"
if ! grep -Fxq "$BASHRC_LINE" ~/.bashrc; then
    echo "$BASHRC_LINE" >> ~/.bashrc
    print_success "Added ROS 2 setup to ~/.bashrc"
fi

WORKSPACE_LINE="source $(pwd)/install/local_setup.bash"
if ! grep -Fxq "$WORKSPACE_LINE" ~/.bashrc; then
    echo "$WORKSPACE_LINE" >> ~/.bashrc
    print_success "Added workspace setup to ~/.bashrc"
fi

# Make launch script executable
if [ -f "launch_go2.sh" ]; then
    chmod +x launch_go2.sh
    print_success "Made launch_go2.sh executable"
fi

# Step 10: Final verification
print_status "Step 10: Verifying installation..."

source install/local_setup.bash

# Check if packages are available
if ros2 pkg list | grep -q "go2_robot_sdk"; then
    print_success "go2_robot_sdk package found"
else
    print_warning "go2_robot_sdk package not found in ROS 2 packages"
fi

if ros2 pkg list | grep -q "go2_interfaces"; then
    print_success "go2_interfaces package found"
else
    print_warning "go2_interfaces package not found in ROS 2 packages"
fi

echo
echo "============================================"
print_success "Build completed successfully!"
echo "============================================"
echo
print_status "Next steps:"
echo "1. Open a new terminal or run: source ~/.bashrc"
echo "2. Run the launch script: ./launch_go2.sh"
echo
print_status "Available launch options:"
echo "- WebRTC connection to Go2 robot"
echo "- Foxglove visualization"
echo "- RViz for 3D visualization"  
echo "- SLAM and navigation capabilities"
echo
print_status "For more information, check the README.md or launch_go2.sh script"
echo
