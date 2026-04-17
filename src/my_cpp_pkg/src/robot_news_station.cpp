#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

using namespace std::chrono_literals;
class RobotNewsStatonNode : public rclcpp::Node {
    public:
        RobotNewsStatonNode() : Node("robot_news_staton") {
            publisher_ = this->create_publisher<example_interfaces::msg::String>("robot_news_1",10);
            timer_ = this->create_wall_timer(0.5s,std::bind(&RobotNewsStatonNode::publishNews,this));
            RCLCPP_INFO(this->get_logger(),"started");

        }
 
    private:
        void publishNews(){
            auto msg = example_interfaces::msg::String();
            msg.data = std::string("this is the data cpp");
            publisher_ ->publish(msg);
        }
        rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
};
 
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotNewsStatonNode>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}