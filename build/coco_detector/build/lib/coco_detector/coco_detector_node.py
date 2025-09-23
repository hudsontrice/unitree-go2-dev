"""
YOLO Image Recognition Node for Unitree Go2 Robot

Subscribes to camera feed and displays live video stream.
Ready for YOLO integration for real-time object detection.
"""

from sensor_msgs.msg import Image
import rclpy
import time
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from cv_bridge import CvBridge
import cv2

class YoloImageRecognitionNode(Node):

    def __init__(self):
        super().__init__('yolo_image_recognition')
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
        if self._image_count % 100 == 0:
            self.get_logger().info(f"Processed {self._image_count} frames: {msg.width}x{msg.height}")
        
        try:
            # Convert ROS Image message to OpenCV format
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")
            
            # Display the image (YOLO detection will be added here)
            cv2.imshow("YOLO Detection", cv_image)
            cv2.waitKey(1)
            
        except Exception as e:
            self.get_logger().error(f'Error processing image: {e}')


def main(args=None):
    rclpy.init(args=args)
    yolo_node = YoloImageRecognitionNode()
    try:
        rclpy.spin(yolo_node)
    except KeyboardInterrupt:
        pass
    finally:
        yolo_node.destroy_node()
        rclpy.shutdown()
        cv2.destroyAllWindows()

if __name__ == '__main__':
    main()
