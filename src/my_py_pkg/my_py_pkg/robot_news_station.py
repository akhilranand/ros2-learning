#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import String 
 
class RobotNewsStation(Node): 
    def __init__(self):
        super().__init__("RobotNewsStation") 
        self.get_logger().info("the publisher has started")
        self.publisher_=self.create_publisher(String,"robot_news_1",10)
        self.timer_=self.create_timer(2,self.publish_data)
    def publish_data(self):
        self.publishData = String()
        self.publishData.data = "haloo this is the published data"   
        self.publisher_.publish(self.publishData) 
 
 
def main(args=None):
    rclpy.init(args=args)
    node = RobotNewsStation() 
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()