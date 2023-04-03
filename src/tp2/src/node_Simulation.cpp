
#include "../include/node_Simulation.hpp"

using namespace Eigen;
using namespace std::chrono_literals;

SimulationPublisher::SimulationPublisher() : Node("NodeSimulation") {
    x_ << 0, 0, 0;
    u1_ = 1.0;
    dt_ = 0.1;
    loop_dt_ = 40ms;
    timer_ = this->create_wall_timer(loop_dt_, std::bind(&SimulationPublisher::timer_callback, this));
    init_interfaces();
    init_parameters();
}

SimulationPublisher::~SimulationPublisher() {}

void SimulationPublisher::init_interfaces() {
    publisher_ = this->create_publisher<geometry_msgs::msg::PoseStamped>("boat_position", 10);
    publisher_marker_ = this->create_publisher<visualization_msgs::msg::Marker>("boat_marker", 10);
    subscriber_ = this->create_subscription<geometry_msgs::msg::Twist>("boat_command", 10, std::bind(&SimulationPublisher::set_u1, this, std::placeholders::_1));
}

std::vector<float> f1(const std::vector<float> &X, float u) {     // State function
    std::vector<float> X1;
    X1.push_back(cos(X[2]));
    X1.push_back(sin(X[2]));
    X1.push_back(u);
    return X1;
}

void euler(std::vector<float>& X, float u1, float dt) {      // Euler method
    auto Y = f1(X, u1);

    for (auto& y : Y) {
        y *= dt;
    }
    std::transform(X.begin(), X.end(), Y.begin(), X.begin(), std::plus<float>());
}

void SimulationPublisher::set_u1(geometry_msgs::msg::Twist twist) {
    double u1 = twist.angular.z;
    u1_ = u1;
}

void SimulationPublisher::init_parameters() {
    this->declare_parameter<double>("x", 0.0);
    this->declare_parameter<double>("y", 0.0);

    x_(0) = this->get_parameter_or<double>("x", -10.0);
    x_(1) = this->get_parameter_or<double>("y", -15.0);
}

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SimulationPublisher>());
    rclcpp::shutdown();
    return 0;
}
