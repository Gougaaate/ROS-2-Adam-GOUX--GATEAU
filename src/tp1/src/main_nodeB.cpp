#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float64.hpp"
#include <iostream>

using namespace std::placeholders;

class Subscriber : public rclcpp::Node {
    public:
        Subscriber() : Node("nodeB"){
    // Créer un subcripter sur le topic "/cap" de type Float64 qui appellera la fonction
    // topic_callback pour chaque nouveau message
            subscription_ = this->create_subscription<std_msgs::msg::Float64>("/cap", 10, std::bind(&Subscriber::topic_callback, this, _1));
        }
    private:

        void topic_callback(const std_msgs::msg::Float64::SharedPtr msg) const {   // Callback function
            RCLCPP_INFO(this->get_logger(), "Heading : '%f'", msg->data);
        }
        rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr subscription_; // Subscription object, class member
    };
    int main(int argc, char * argv[]) {
        rclcpp::init(argc, argv);
        rclcpp::spin(std::make_shared<Subscriber>());
        rclcpp::shutdown();
        return 0;
    }