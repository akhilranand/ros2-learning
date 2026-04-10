#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String
 
 
class MobilePhone(Node): 
    def __init__(self):
        super().__init__("MobilePhone") 
        self.subscriber = self.create_subscription(String,"robot_news_1",self.callback_robot_news,10)

    def callback_robot_news(self,msg:String):
        self.get_logger().info(msg.data)

 
 
def main(args=None):
    rclpy.init(args=args)
    node = MobilePhone()
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()