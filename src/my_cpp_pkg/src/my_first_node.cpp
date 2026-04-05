#include "rclcpp/rclcpp.hpp"


class MyNode : public rclcpp::Node{
    public:
        MyNode() : Node("cpp_test"),counter_(0){
             RCLCPP_INFO(this->get_logger(),"hallo world");
             timer_ = this->create_wall_timer(
                std::chrono::seconds(1),
                std::bind(&MyNode::timerCallback , this ));
        }
    private:
    void timerCallback(){
        RCLCPP_INFO(this->get_logger(),"helo %d",counter_);
        counter_ ++;

    }
        rclcpp::TimerBase::SharedPtr timer_;
        int counter_;
};



int main(int argc ,char **argv){
    rclcpp::init(argc , argv);
    auto node = std::make_shared<MyNode>();
    rclcpp::spin(node);
    rclcpp::shutdown(); 
    return 0;
}   



// #include "rclcpp/rclcpp.hpp"

// class MyNode : public rclcpp::Node
// {
// public:
//     // Constructor
//     MyNode() : Node("cpp_test")
//     {
//         count = 0;

//         RCLCPP_INFO(this->get_logger(), "Hello world");

//         timer = this->create_wall_timer(
//             std::chrono::seconds(1),
//             std::bind(&MyNode::sayHello, this)
//         );
//     }

// private:
//     // Member function
//     void sayHello()
//     {
//         RCLCPP_INFO(this->get_logger(), "Count = %d", count);
//         count++;
//     }

//     // Data members
//     int count;
//     rclcpp::TimerBase::SharedPtr timer;
// };

// int main(int argc, char **argv)
// {
//     rclcpp::init(argc, argv);

//     auto node = std::make_shared<MyNode>();

//     rclcpp::spin(node);

//     rclcpp::shutdown();
//     return 0;
// }

   