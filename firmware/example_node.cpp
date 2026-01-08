#include <Arduino.h>
#include <micro_ros_arduino.h>
#include <rcl/rcl.h>
#include <geometry_msgs/msg/twist.h>

// ROS 2 Objects
rcl_subscription_t subscriber;
geometry_msgs__msg__Twist msg;
rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;

// Callback: will be called, when Pi sends move
void subscription_callback(const void * msvin) {
  const geometry_msgs__msg__Twist * msg = (const geometry_msgs__msg__Twist *)msvin;
  
  // TODO: Calculation of PWM for VNH2SP30 motor driver
  // msg->linear.x  = forward/backwards (m/s)
  // msg->angular.z = rotation (rad/s)
}

void setup() {
  set_microros_transports();
  delay(2000);

  allocator = rcl_get_default_allocator();
  // Setup support & Node
  rclc_support_init(&support, 0, NULL, &allocator);
  rclc_node_init_default(&node, "esp32_motor_node", "", &support);

  // initialize subsciber for /cmd_vel 
  rclc_subscription_init_default(
    &subscriber, &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
    "cmd_vel");

  // Executor (handles incoming messages)
  rclc_executor_init(&executor, &support.context, 1, &allocator);
  rclc_executor_add_subscription(&executor, &subscriber, &msg, &subscription_callback, ON_NEW_DATA);
}

void loop() {
  rclc_executor_spin_some(&executor, RCL_MS_TO_NS(10));
}