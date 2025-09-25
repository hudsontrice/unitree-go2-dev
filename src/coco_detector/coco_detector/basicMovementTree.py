#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
import time

class SpinRobot(Node):
    def __init__(self):
        super().__init__('spin_robot')
        
        # Create parameters with defaults
        self.declare_parameter('cmd_topic', 'cmd_vel')
        self.declare_parameter('angular_speed', 0.8)  # rad/s
        self.declare_parameter('rate_hz', 10.0)
        self.declare_parameter('duration', 0.0)  # 0 = infinite
        
        # Get parameter values
        self.cmd_topic = self.get_parameter('cmd_topic').value
        self.angular_speed = self.get_parameter('angular_speed').value
        self.rate_hz = self.get_parameter('rate_hz').value
        self.duration = self.get_parameter('duration').value
        
        # Create publisher
        self.pub = self.create_publisher(Twist, self.cmd_topic, 10)
        
        # Start timer
        period = 1.0 / self.rate_hz
        self.timer = self.create_timer(period, self.timer_callback)
        self.start_time = time.time()
        
        self.get_logger().info(f"Starting to spin with angular_speed={self.angular_speed} rad/s")
        
    def timer_callback(self):
        # Check if we should stop based on duration
        if self.duration > 0 and (time.time() - self.start_time) > self.duration:
            self.get_logger().info("Spin duration complete, stopping robot")
            self.pub.publish(Twist())  # All zeros = stop
            self.timer.cancel()
            return
        
        # Create and publish spin command
        cmd = Twist()
        cmd.angular.z = self.angular_speed
        self.pub.publish(cmd)

def main(args=None):
    rclpy.init(args=args)
    node = SpinRobot()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Interrupted, stopping robot")
        # Send stop command
        stop_cmd = Twist()
        node.pub.publish(stop_cmd)
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()