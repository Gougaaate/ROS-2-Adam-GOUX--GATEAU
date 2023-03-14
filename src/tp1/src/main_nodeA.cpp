#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <math.h>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float64.hpp"

using namespace std::chrono_literals;
/*
 * Class that inherits from the rclcpp::Node object.
 * You can choose to separate your class into an .hpp and .cpp file.
 */

class NodeA : public rclcpp::Node {
    public:
        /* Constructor of your node with the name "nodeA" */

        NodeA() : Node("nodeA") {
            // Creates a publisher of type std_msgs/msg/String on the "topic" topic, with a maximum queue size of 10 messages.

            publisher_ = this->create_publisher<std_msgs::msg::Float64>("topic", 10);
            timer_ = this->create_wall_timer(500ms, std::bind(&NodeA::timer_callback, this));     // Creates a timer that calls the time_callback function every 500ms.

            // Note that there are several possible time bases.
        }

    private:
        /* Timer callback function */

        void timer_callback() {

            auto message = std_msgs::msg::Float64();               // Creates a message object of type Float64.
            message.data = 90 * sin(this -> now().seconds());   // Fills the message content.

            // Prints a log message to the console (fprintf format).
            // It is also possible to use RCLCPP_WARN.
            // Outside a node, rclcpp::get_logger("rclcpp") can be used.

            RCLCPP_INFO(this->get_logger(), "Publishing: '%f'", message.data);
            publisher_->publish(message);   // Publishes the message using the publisher object.
        }
        rclcpp::TimerBase::SharedPtr timer_; // Timer object.
        rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
     };

int main(int argc, char *argv[]) {

    rclcpp::init(argc, argv);       // Initialize ROS 2 for the executable.

    rclcpp::spin(std::make_shared<NodeA>());// Creates the node and wait for messages or timer events. Note that this function is blocking!

    rclcpp::shutdown();         // Shuts down ROS-2
    return 0;
}
