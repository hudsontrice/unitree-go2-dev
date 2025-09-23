# NOTE: This file intentionally copies the existing COCO node content without changes.
# We'll keep behavior identical and only rename package/paths per your request.

from sensor_msgs.msg import Image
import rclpy
import time
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from cv_bridge import CvBridge
import cv2

class ImageSubscriber(Node):

    def __init__(self):
        super().__init__('minimal_subscriber')
        camera_qos = QoSProfile(
            history=HistoryPolicy.SYSTEM_DEFAULT,
            depth=10,
            reliability=ReliabilityPolicy.SYSTEM_DEFAULT,
            durability=DurabilityPolicy.SYSTEM_DEFAULT
        )
        
        self.subscription = self.create_subscription(
            Image,
            "/camera/image_raw",
            self.listener_callback,
            camera_qos)
        self._image_count = 0
        self.bridge = CvBridge()

    def listener_callback(self, msg):
        self._image_count += 1
        self.get_logger().info(f"Received image {self._image_count}: {msg.width}x{msg.height}, encoding: {msg.encoding}")
        cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")
        cv2.imshow("Demo", cv_image)
        cv2.waitKey(1)
        # self.get_logger().info('I heard: "%s"' % msg.data)


def main(args=None):
    rclpy.init(args=args)
    node = ImageSubscriber()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
        cv2.destroyAllWindows()
