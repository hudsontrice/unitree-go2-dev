#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist


class SpinSearcher(Node):
    """Minimal node that spins in place continuously.

    Params:
      - cmd_vel_topic (string): topic to publish Twist to (default: 'cmd_vel')
      - search_spin_speed (double): angular speed rad/s (default: 0.3)
      - publish_rate_hz (double): publish rate (default: 10.0)
    """

    def __init__(self):
        super().__init__('follow_person_node')

        # Parameters
        self.declare_parameter('cmd_vel_topic', 'cmd_vel')
        self.declare_parameter('search_spin_speed', 0.3)
        self.declare_parameter('publish_rate_hz', 10.0)

        cmd_vel_topic = self.get_parameter('cmd_vel_topic').value
        self.search_spin_speed = float(self.get_parameter('search_spin_speed').value)
        publish_rate_hz = float(self.get_parameter('publish_rate_hz').value)

        # Publisher
        self.cmd_pub = self.create_publisher(Twist, cmd_vel_topic, 10)

        # Timer for periodic publish
        period = 1.0 / max(publish_rate_hz, 0.1)
        self.timer = self.create_timer(period, self._on_timer)

        self.get_logger().info(
            f"SpinSearcher started: topic='{cmd_vel_topic}', spin={self.search_spin_speed:.2f} rad/s"
        )

    def _on_timer(self):
        cmd = Twist()
        cmd.angular.z = self.search_spin_speed
        cmd.linear.x = 0.0
        self.cmd_pub.publish(cmd)


def main(args=None):
    rclpy.init(args=args)
    node = SpinSearcher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        # Stop robot on exit
        try:
            stop = Twist()
            node.cmd_pub.publish(stop)
        except Exception:
            pass
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
