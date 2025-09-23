# """Detects COCO objects in image and publishes in ROS2.

# Subscribes to /image and publishes Detection2DArray message on topic /detected_objects.
# Also publishes (by default) annotated image with bounding boxes on /annotated_image.
# Uses PyTorch and FasterRCNN_MobileNet model from torchvision.
# Bounding Boxes use image convention, ie center.y = 0 means top of image.
# """

# import collections
# import numpy as np
# import rclpy
# from rclpy.node import Node
# from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
# from sensor_msgs.msg import Image
# from vision_msgs.msg import BoundingBox2D, ObjectHypothesis, ObjectHypothesisWithPose
# from vision_msgs.msg import Detection2D, Detection2DArray
# from cv_bridge import CvBridge
# import torch
# from torchvision.models import detection as detection_model
# from torchvision.utils import draw_bounding_boxes
# import cv2
# Detection = collections.namedtuple("Detection", "label, bbox, score")

# class CocoDetectorNode(Node):
#     """Detects COCO objects in image and publishes on ROS2.

#     Subscribes to /image and publishes Detection2DArray on /detected_objects.
#     Also publishes augmented image with bounding boxes on /annotated_image.
#     """

#     # pylint: disable=R0902 disable too many instance variables warning for this class
#     def __init__(self):
#         super().__init__("coco_detector_node")
#         self.declare_parameter('device', 'cpu')
#         self.declare_parameter('detection_threshold', 0.9)
#         self.declare_parameter('publish_annotated_image', True)
#         self.device = self.get_parameter('device').get_parameter_value().string_value
#         self.detection_threshold = \
#             self.get_parameter('detection_threshold').get_parameter_value().double_value
        
#         # Create QoS profile compatible with camera publisher
#         camera_qos = QoSProfile(
#             history=HistoryPolicy.KEEP_LAST,
#             depth=10,
#             reliability=ReliabilityPolicy.BEST_EFFORT,
#             durability=DurabilityPolicy.VOLATILE
#         )
        
#         self.subscription = self.create_subscription(
#             Image,
#             "/camera/image_raw",
#             self.listener_callback,
#             camera_qos)
#         # self.detected_objects_publisher = \
#         #     self.create_publisher(Detection2DArray, "detected_objects", 10)
        
#         if self.get_parameter('publish_annotated_image').get_parameter_value().bool_value:
#             self.annotated_image_publisher = \
#                 self.create_publisher(Image, "annotated_image", 10)
#         else:
#             self.annotated_image_publisher = None
#         self.bridge = CvBridge()
#         self.model = detection_model.fasterrcnn_mobilenet_v3_large_320_fpn(
#             weights="FasterRCNN_MobileNet_V3_Large_320_FPN_Weights.COCO_V1",
#             progress=True,
#             weights_backbone="MobileNet_V3_Large_Weights.IMAGENET1K_V1").to(self.device)
#         self.class_labels = \
#             detection_model.FasterRCNN_MobileNet_V3_Large_320_FPN_Weights.DEFAULT.meta["categories"]
#         self.model.eval()
#         self.get_logger().info("Node has started.")

#     def mobilenet_to_ros2(self, detection, header):
#         """Converts a Detection tuple(label, bbox, score) to a ROS2 Detection2D message."""

#         detection2d = Detection2D()
#         detection2d.header = header
#         object_hypothesis_with_pose = ObjectHypothesisWithPose()
#         object_hypothesis = ObjectHypothesis()
#         object_hypothesis.class_id = self.class_labels[detection.label]
#         object_hypothesis.score = detection.score.detach().item()
#         object_hypothesis_with_pose.hypothesis = object_hypothesis
#         detection2d.results.append(object_hypothesis_with_pose)
#         bounding_box = BoundingBox2D()
#         bounding_box.center.position.x = float((detection.bbox[0] + detection.bbox[2]) / 2)
#         bounding_box.center.position.y = float((detection.bbox[1] + detection.bbox[3]) / 2)
#         bounding_box.center.theta = 0.0
#         bounding_box.size_x = float(2 * (bounding_box.center.position.x - detection.bbox[0]))
#         bounding_box.size_y = float(2 * (bounding_box.center.position.y - detection.bbox[1]))
#         detection2d.bbox = bounding_box
#         return detection2d

#     def publish_annotated_image(self, filtered_detections, header, image):
#         """Draws the bounding boxes on the image and publishes to /annotated_image"""
#         try:
#             # if len(filtered_detections) > 0:
#             #     pred_boxes = torch.stack([detection.bbox for detection in filtered_detections])
#             #     pred_labels = [f"{self.class_labels[detection.label]}: {detection.score:.2f}" 
#             #                   for detection in filtered_detections]
#             #     # Convert image to uint8 format for bounding box drawing
#             #     image_uint8 = (torch.tensor(image) * 255).byte()
#             #     annotated_image = draw_bounding_boxes(image_uint8, pred_boxes,
#             #                                           pred_labels, colors="yellow", width=8) # Changed bounding box width
#             #     # Convert back to float for cv_bridge
#             #     annotated_image = annotated_image.float() / 255.0
#             # else:
#             #     annotated_image = torch.tensor(image, dtype=torch.float32)
            
#             # # Convert to numpy and transpose for OpenCV format (HWC)
#             # numpy_image = annotated_image.numpy().transpose(1, 2, 0)
#             # # Ensure values are in [0, 255] range for cv_bridge
#             # numpy_image = (numpy_image * 255).astype(np.uint8)

#             # cv2.imshow("Annotated Image", numpy_image)
#             # cv2.waitKey(1)
#             numpy_image = (image.transpose(1, 2, 0) * 255).astype(np.uint8)

#             self.get_logger().info(f"Publishing annotated image with {len(filtered_detections)} detections")
            
#             ros2_image_msg = self.bridge.cv2_to_imgmsg(numpy_image, encoding="rgb8")
#             ros2_image_msg.header = header
#             self.annotated_image_publisher.publish(ros2_image_msg)
            
#         except Exception as e:
#             self.get_logger().error(f"Error creating annotated image: {str(e)}")

#     def listener_callback(self, msg):
#         """Reads image and publishes on /detected_objects and /annotated_image."""
#         try:
#             # Log first few image receptions
#             if not hasattr(self, '_image_count'):
#                 self._image_count = 0
#             self._image_count += 1
            
#             # if self._image_count <= 3:
#             self.get_logger().info(f"Received image {self._image_count}: {msg.width}x{msg.height}, encoding: {msg.encoding}")
            
#             cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="rgb8")
#             # cv_image = cv2.cvtColor(cv_image, cv2.COLOR_BGR2RGB)
#             image = cv_image.copy().transpose((2, 0, 1))
#             batch_image = np.expand_dims(image, axis=0)
#             tensor_image = torch.tensor(batch_image/255.0, dtype=torch.float, device=self.device)
            
#             with torch.no_grad():  # Improve performance by disabling gradients
#                 mobilenet_detections = self.model(tensor_image)[0]
            
#             filtered_detections = [Detection(label_id, box, score) for label_id, box, score in
#                 zip(mobilenet_detections["labels"],
#                 mobilenet_detections["boxes"],
#                 mobilenet_detections["scores"]) if score >= self.detection_threshold]
            
#             # Log detections periodically
#             # if self._image_count % 30 == 0:  # Every ~1 second at 30fps
#             self.get_logger().info(f"Processed {self._image_count} images, found {len(filtered_detections)} objects")
            
#             # detection_array = Detection2DArray()
#             # detection_array.header = msg.header
#             # detection_array.detections = \
#             #     [self.mobilenet_to_ros2(detection, msg.header) for detection in filtered_detections]
#             # # self.detected_objects_publisher.publish(detection_array)
            
#             if self.annotated_image_publisher is not None:
#                 self.publish_annotated_image(filtered_detections, msg.header, image)
                
#         except Exception as e:
#             self.get_logger().error(f"Error processing image: {str(e)}")
#             import traceback
#             self.get_logger().error(traceback.format_exc())


# rclpy.init()
# coco_detector_node = CocoDetectorNode()
# rclpy.spin(coco_detector_node)
# coco_detector_node.destroy_node()
# rclpy.shutdown()

from sensor_msgs.msg import Image
import rclpy
import time
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy, DurabilityPolicy
from cv_bridge import CvBridge
import cv2
from ultralytics import YOLO
import traceback

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
        # NEW: publisher for annotated image
        self.annotated_pub = self.create_publisher(Image, 'annotated_image', 10)

    def listener_callback(self, msg):
        self._image_count += 1
        self.get_logger().info(f"Received image {self._image_count}: {msg.width}x{msg.height}, encoding: {msg.encoding}")
        cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

        # Load YOLO model (kept as-is, though moving to __init__ is faster)
        self.model = YOLO('yolov8n.pt')

        # Run YOLO detection on the image
        results = self.model(cv_image)
        result = results[0]

        # Draw bounding boxes on the image
        annotated_img = result.plot()

        # Publish annotated image (instead of GUI window)
        try:
            img_msg = self.bridge.cv2_to_imgmsg(annotated_img, encoding='bgr8')
            img_msg.header = msg.header
            self.annotated_pub.publish(img_msg)
        except Exception as e:
            self.get_logger().error(f"Failed to publish annotated image: {e}")

        # GUI disabled for headless environments
        # cv2.imshow("YOLO Detection", annotated_img)
        # cv2.waitKey(1)


rclpy.init()
imageSub = ImageSubscriber()
rclpy.spin(imageSub)
imageSub.destroy_node()
rclpy.shutdown()
