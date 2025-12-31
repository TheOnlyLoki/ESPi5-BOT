# ESPi5-BOT
A ROS 2-based autonomous rover using a Raspberry Pi 5 and ESP32 as its dual-brain system. Features D500 LiDAR-based SLAM for navigation.

This is my first DIY-Robot-Project, so forgive me if some electrical stuff looks nooby. I am a CS Student, not an Electrical Engineer :D

## License
This project is dual-licensed:
* **Software:** Licensed under the [MIT License](LICENSE).
* **Hardware & Designs:** Licensed under [CC-BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/).

## Component List
### Computing & Logic
| Component | Specification | Function |
| :--- | :--- | :--- |
| **Raspberry Pi 5** | 8GB RAM recommended | High-level processing (SLAM, Navigation, Vision) |
| **ESP32 NodeMCU** | DevKit V1 (WROOM-32) | Low-level real-time control (micro-ROS, PWM, Odometry) |
| **0.96" OLED Display** | I2C SSD1306 (128x64) | Status dashboard (IP, Battery, ROS 2 status) |

### Power System
| Component | Specification | Function |
| :--- | :--- | :--- |
| **3S Li-Ion Battery** | 11.1V - 12.6V (3x 18650) | Main power source |
| **3S BMS Board** | 20A-40A with Balancing | Battery protection & health management |
| **Pololu D24V50F5** | Step-down (5V / 5A) | Stable power for Pi 5 and ESP32 |
| **Electrolytic Cap** | 1000µF / 25V | Smoothing voltage spikes from motors |

### Drivetrain & Sensors
| Component | Specification | Function |
| :--- | :--- | :--- |
| **VNH2SP30** | Dual Monster Moto Shield | High-current motor driver |
| **2x DC Motors** | 6V Gear motors w/ Encoders | Propulsion and distance measurement |
| **D500 LiDAR** | 360° Laser Scanner | Environment mapping and obstacle detection |

## Repository Structure
* `/firmware` - ESP32 micro-ROS source code (PlatformIO).
* `/ros2_ws` - ROS 2 workspace (Packages, URDF, Launch files).
* `/hardware` - Fritzing schematics and CAD files (.STL/.STEP).
* `/docs` - Wiring diagrams and project documentation (you wish lol).
