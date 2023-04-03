#include <eigen3/Eigen/Dense>
#include <chrono>
#include <functional>
#include <cmath>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "tf2/LinearMath/Quaternion.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "visualization_msgs/msg/marker.hpp"

using namespace Eigen;
using namespace std::chrono_literals;

class SimulationPublisher : public rclcpp::Node {
    public:
        SimulationPublisher();
        ~SimulationPublisher();
        void set_u1(geometry_msgs::msg::Twist twist);
        void euler();
        void init_interfaces();
        void init_parameters();
        void timer_callback();
    private:
        Matrix<double, 3, 1> x_;
        double u1_;
        double dt_;
        std::chrono::milliseconds loop_dt_;
        rclcpp::TimerBase::SharedPtr timer_;                                                // objet timer
        rclcpp::Publisher<geometry_msgs::msg::PoseStamped>::SharedPtr publisher_;           // objet publisher
        rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr publisher_marker_;    // objet publisher
        rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscriber_;             // objet subscriber
};
