# Unitree Go2 Python Control & Vision

This repository contains Python scripts and utilities for controlling the Unitree Go2 quadruped robot, including high-level movement commands and real-time camera-based person/color tracking using YOLOv8.

## Directory Structure

```
go2_py/
├── unitree_sdk2_python/
│   ├── example/
│   │   └── go2/
│   │       ├── high_level/ # Defaults
│   │       │   ├── go2_sport_client.py
│   │       │   ├── move_test.py
│   │       │   ├── fullspin_test.py
│   │       │   ├── camera_stream.py
│   │       │   ├── camera_yolo.py
│   │       └── hudson_scripts/                 # Added by me
│   │           ├── person_track.py
│   │           ├── person_track_movement.py
│   │           ├── spin_detect_people_led.py   # Non-functional
│   │           ├── color_track.py
│   │           ├── color_track_advanced.py     # Forked
│   │           └── person_track_advanced.py    # Forked
│   └── ... (SDK source files)
├── yolov8n.pt / yolov8m.pt / yolov8x.pt   # YOLOv8 model weights (place here or in hudson_scripts)
└── README.md
```

## Setup Instructions

1. **Install dependencies:**
	 ```bash
	 sudo apt update
	 sudo apt install python3-pip
	 pip3 install ultralytics opencv-python numpy cyclonedds==0.10.2
	 ```

2. **Download YOLOv8 weights:**
	 - In the individual launch scripts, change the variable model to yolov8[n, s, m, l, x]
	 - Place `yolov8n.pt`, `yolov8m.pt`, or `yolov8x.pt` in `hudson_scripts/`.

## How to Launch

- **Movement and tracking scripts:**
	```bash
	cd unitree_sdk2_python/example/go2/hudson_scripts
	python3 person_track_movement.py
	# python3 color_track_rotate.py
	```

- **Camera streaming:**
	```bash
	python3 camera_stream.py
	# python3 camera_yolo.py
	```

- **Basic movement:**
	```bash
	cd unitree_sdk2_python/example/go2/high_level
	python3 go2_sport_client.py
	# python3 move_test.py
	```

## Notes

- Edit configuration variables at the top of each script to set network interface, color presets, model weights, and control gains.
- For YOLO-based scripts, ensure the correct `.pt` file is present and referenced in the script.
- For robot control, connect your PC to the robot's network and set the correct interface name in the script.

---

## Extracted from official SDK README

### Installation
#### Dependencies
- Python >= 3.8
- cyclonedds == 0.10.2
- numpy
- opencv-python

#### Installing from source
```bash
cd ~
sudo apt install python3-pip
git clone https://github.com/unitreerobotics/unitree_sdk2_python.git
cd unitree_sdk2_python
pip3 install -e .
```

#### FAQ: cyclonedds error
If you see:
```
Could not locate cyclonedds. Try to set CYCLONEDDS_HOME or CMAKE_PREFIX_PATH
```
Compile and install cyclonedds:
```bash
cd ~
git clone https://github.com/eclipse-cyclonedds/cyclonedds -b releases/0.10.x 
cd cyclonedds && mkdir build install && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=../install
cmake --build . --target install
```
Then set CYCLONEDDS_HOME and install:
```bash
cd ~/unitree_sdk2_python
export CYCLONEDDS_HOME="~/cyclonedds/install"
pip3 install -e .
```
See: https://pypi.org/project/cyclonedds/#installing-with-pre-built-binaries

### Usage
Example programs are in `/example`. Before running, configure the robot's network as per https://support.unitree.com/home/en/developer/Quick_start.

#### DDS Communication
```bash
python3 ./example/helloworld/publisher.py
python3 ./example/helloworld/subscriber.py
```
Data structure is defined in `user_data.py`.

#### High-Level Status and Control
```bash
python3 ./example/high_level/read_highstate.py enp2s0
python3 ./example/high_level/sportmode_test.py enp2s0
```
Replace `enp2s0` with your network interface name.

#### Low-Level Status and Control
```bash
python3 ./example/low_level/lowlevel_control.py enp2s0
```
Replace `enp2s0` with your network interface name.

#### Wireless Controller Status
```bash
python3 ./example/wireless_controller/wireless_controller.py enp2s0
```

#### Front Camera
```bash
python3 ./example/front_camera/camera_opencv.py enp2s0
```

#### Obstacle Avoidance Switch
```bash
python3 ./example/obstacles_avoid_switch/obstacles_avoid_switch.py enp2s0
```

#### Light and volume control
```bash
python3 ./example/vui_client/vui_client_example.py enp2s0
```
