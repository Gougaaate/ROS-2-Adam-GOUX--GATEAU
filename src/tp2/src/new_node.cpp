#include <chrono>
#include <functional>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include <eigen3/Eigen/Dense>
#include <cmath>
#include <vector>

using namespace Eigen;
using namespace std::chrono_literals;

class new_node : public rclcpp::Node {
    public:
        new_node() : Node("new_node") {
            publisher_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("/position", 10);
            timer_ = this->create_wall_timer(100ms, std::bind(&new_node::timer_callback, this));     // Creates a timer that calls the time_callback function every 100ms.
        }
    private:
        void timer_callback() {

            auto message = geometry_msgs::msg::PoseStamped();               // Creates a message object of type Float64.
            // Prints a log message to the console (fprintf format).
            // It is also possible to use RCLCPP_WARN.
            // Outside a node, rclcpp::get_logger("rclcpp") can be used.

            publisher_->publish(message);    // Publishes the message using the publisher object.
        }
        rclcpp::TimerBase::SharedPtr timer_; // Timer object.
        rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr publisher_;
};

std::vector<float> f1(const std::vector<float> &X, float u) {     // State function
    std::vector<float> X1;
    X1.push_back(cos(X[2]));
    X1.push_back(sin(X[2]));
    X1.push_back(u);
    return X1;
}

void integration_euler(std::vector<float> &X, float u1, float dt) {         // Euler method
    std::vector<float> Y = f1(X,u1);
    for (size_t i = 0; i < X.size(); i++) {
        Y[i] *= dt;
    }
    for (size_t i = 0; i < X.size(); i++) {
        X[i] += Y[i];
    }
}

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<new_node>());
    rclcpp::shutdown();
    return 0;
}