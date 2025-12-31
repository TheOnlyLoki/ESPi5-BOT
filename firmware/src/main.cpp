#include <Arduino.h>
#include <micro_ros_arduino.h>
#include <rcl/rcl.h>
#include <geometry_msgs/msg/twist.h>

// ROS 2 Objekte
rcl_subscription_t subscriber;
geometry_msgs__msg__Twist msg;
rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;

// Callback: Wird aufgerufen, wenn der Pi 5 einen Fahrbefehl sendet
void subscription_callback(const void * msvin) {
  const geometry_msgs__msg__Twist * msg = (const geometry_msgs__msg__Twist *)msvin;
  
  // Hier rechnest du später die Werte in PWM für den VNH2SP30 um
  // msg->linear.x  = Vorwärts/Rückwärts (m/s)
  // msg->angular.z = Drehung (rad/s)
}

void setup() {
  set_microros_transports();
  delay(2000);

  allocator = rcl_get_default_allocator();
  // Setup Unterstützung & Node
  rclc_support_init(&support, 0, NULL, &allocator);
  rclc_node_init_default(&node, "esp32_motor_node", "", &support);

  // Subscriber für /cmd_vel initialisieren
  rclc_subscription_init_default(
    &subscriber, &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
    "cmd_vel");

  // Executor (verarbeitet die eingehenden Nachrichten)
  rclc_executor_init(&executor, &support.context, 1, &allocator);
  rclc_executor_add_subscription(&executor, &subscriber, &msg, &subscription_callback, ON_NEW_DATA);
}

void loop() {
  rclc_executor_spin_some(&executor, RCL_MS_TO_NS(10));
}