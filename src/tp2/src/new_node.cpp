#include <chrono>
#include <functional>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <eigen3/Eigen/Dense>
#include <cmath>
#include <vector>
using namespace Eigen;
using namespace std::chrono_literals;

class new_node : public rclcpp::Node {
    public:
        new_node() : Node("new_node") {
        }
};

std::vector<float> f1(const std::vector<float> &X, float u) {     // State function
    std::vector<float> X1;
    X1.push_back(cos(X[2]));
    X1.push_back(sin(X[2]));
    X1.push_back(u);
    return X1;
}

void integration_euler(std::vector<float> &X, float u1, float dt) {         // Euler method
    X = X + dt * f1(X,u1)
}

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<new_node>());
    rclcpp::shutdown();
    return 0;
}