first init git submodules
then rosdep install and colcon build
```bash
#do this in main folder
git submodule update --init --recursive

# in ros2_ws
source /opt/ros/humble/setup.bash

rosdep update
rosdep install -y \
  --from-paths ./src \
  --ignore-src
colcon build \
  --symlink-install
```

**IMPORTANT NOTE**:
/ros2_ws/install/ldlidar_node/share/ldlidar_node/params/ldlidar.yaml configure serial port !!!
```yaml
    serial_port: '/dev/ttyUSB0' # serial port name example
```