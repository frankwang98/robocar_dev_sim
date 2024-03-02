#ifndef ROBOCAR_GAZEBO_H_
#define ROBOCAR_GAZEBO_H_

#include <ros/ros.h>

#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>

#define DEG2RAD (M_PI / 180.0)
#define RAD2DEG (180.0 / M_PI)

#define CENTER 0
#define LEFT   1
#define RIGHT  2

#define LINEAR_VELOCITY  0.3
#define ANGULAR_VELOCITY 1.5

#define GET_TB3_DIRECTION 0
#define TB3_DRIVE_FORWARD 1
#define TB3_RIGHT_TURN    2
#define TB3_LEFT_TURN     3

class RobocarGazebo {
private:
    ros::NodeHandle nh_;
    ros::NodeHandle nh_priv_;

    // ros::Time last_cmd_vel_time_;
    // ros::Time prev_update_time_;

    ros::Publisher cmd_vel_pub_;

    ros::Subscriber laser_scan_sub_;
    ros::Subscriber odom_sub_;

    // Variables
    double escape_range_;
    double check_forward_dist_;
    double check_side_dist_;

    double scan_data_[3] = {0.0, 0.0, 0.0};

    double tb3_pose_;
    double prev_tb3_pose_;

public:
    RobocarGazebo();
    ~RobocarGazebo();

    /**
     * @brief init
     * 
     * @return true 
     * @return false 
     */
    bool init();

    /**
     * @brief controlLoop
     * 
     * @return true 
     * @return false 
     */
    bool controlLoop();

private:
    /**
     * @brief updatecommandVelocity
    */
    void updatecommandVelocity(double linear, double angular);

    /**
     * laserScanMsgCallBack
    */
    void laserScanMsgCallBack(const sensor_msgs::LaserScan::ConstPtr &msg);

    /**
     * odomMsgCallBack
    */
    void odomMsgCallBack(const nav_msgs::Odometry::ConstPtr &msg);
};

#endif
