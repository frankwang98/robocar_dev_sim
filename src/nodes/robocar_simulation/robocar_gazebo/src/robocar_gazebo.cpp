#include "robocar_gazebo.h"

RobocarGazebo::RobocarGazebo()
    : nh_priv_("~")
{
    // Init gazebo robocar node
    ROS_INFO("RobocarGazebo Simulation Node Init");
    auto ret = init();
    ROS_ASSERT(ret);
}

RobocarGazebo::~RobocarGazebo()
{
    updatecommandVelocity(0.0, 0.0);
    ros::shutdown();
}

bool RobocarGazebo::init()
{
    // initialize ROS parameter 接收仿真跑参数
    std::string cmd_vel_topic_name = nh_.param<std::string>("cmd_vel_topic_name", "");

    // initialize variables
    escape_range_ = 30.0 * DEG2RAD;
    check_forward_dist_ = 0.7;
    check_side_dist_ = 0.6;

    tb3_pose_ = 0.0;
    prev_tb3_pose_ = 0.0;

    // initialize publishers
    cmd_vel_pub_ = nh_.advertise<geometry_msgs::Twist>(cmd_vel_topic_name, 10);

    // initialize subscribers
    laser_scan_sub_ = nh_.subscribe("scan", 10, &RobocarGazebo::laserScanMsgCallBack, this);
    odom_sub_ = nh_.subscribe("odom", 10, &RobocarGazebo::odomMsgCallBack, this);

    return true;
}

void RobocarGazebo::odomMsgCallBack(const nav_msgs::Odometry::ConstPtr &msg)
{
    double siny = 2.0 * (msg->pose.pose.orientation.w * msg->pose.pose.orientation.z + msg->pose.pose.orientation.x * msg->pose.pose.orientation.y);
    double cosy = 1.0 - 2.0 * (msg->pose.pose.orientation.y * msg->pose.pose.orientation.y + msg->pose.pose.orientation.z * msg->pose.pose.orientation.z);

    // pose info
    tb3_pose_ = atan2(siny, cosy);
}

void RobocarGazebo::laserScanMsgCallBack(const sensor_msgs::LaserScan::ConstPtr &msg)
{
    uint16_t scan_angle[3] = {0, 30, 330};

    // laser info
    for (int num = 0; num < 3; num++)
    {
        if (std::isinf(msg->ranges.at(scan_angle[num])))
        {
            scan_data_[num] = msg->range_max;
        }
        else
        {
            scan_data_[num] = msg->ranges.at(scan_angle[num]);
        }
    }
}

void RobocarGazebo::updatecommandVelocity(double linear, double angular)
{
    geometry_msgs::Twist cmd_vel;

    // set value and publish
    cmd_vel.linear.x = linear;
    cmd_vel.angular.z = angular;

    cmd_vel_pub_.publish(cmd_vel);
}

bool RobocarGazebo::controlLoop()
{
    static uint8_t turtlebot3_state_num = 0;
    // auto control simulation
    switch (turtlebot3_state_num)
    {
    case GET_TB3_DIRECTION:
        if (scan_data_[CENTER] > check_forward_dist_)
        {
            if (scan_data_[LEFT] < check_side_dist_)
            {
                prev_tb3_pose_ = tb3_pose_;
                turtlebot3_state_num = TB3_RIGHT_TURN;
            }
            else if (scan_data_[RIGHT] < check_side_dist_)
            {
                prev_tb3_pose_ = tb3_pose_;
                turtlebot3_state_num = TB3_LEFT_TURN;
            }
            else
            {
                turtlebot3_state_num = TB3_DRIVE_FORWARD;
            }
        }

        if (scan_data_[CENTER] < check_forward_dist_)
        {
            prev_tb3_pose_ = tb3_pose_;
            turtlebot3_state_num = TB3_RIGHT_TURN;
        }
        break;

    case TB3_DRIVE_FORWARD:
        updatecommandVelocity(LINEAR_VELOCITY, 0.0);
        turtlebot3_state_num = GET_TB3_DIRECTION;
        break;

    case TB3_RIGHT_TURN:
        if (fabs(prev_tb3_pose_ - tb3_pose_) >= escape_range_)
            turtlebot3_state_num = GET_TB3_DIRECTION;
        else
            updatecommandVelocity(0.0, -1 * ANGULAR_VELOCITY);
        break;

    case TB3_LEFT_TURN:
        if (fabs(prev_tb3_pose_ - tb3_pose_) >= escape_range_)
            turtlebot3_state_num = GET_TB3_DIRECTION;
        else
            updatecommandVelocity(0.0, ANGULAR_VELOCITY);
        break;

    default:
        turtlebot3_state_num = GET_TB3_DIRECTION;
        break;
    }

    return true;
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "RobocarGazebo");
    RobocarGazebo robocar_gazebo;

    ros::Rate loop_rate(125);

    while (ros::ok())
    {
        robocar_gazebo.controlLoop();
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}