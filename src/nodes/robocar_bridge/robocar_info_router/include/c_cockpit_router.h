/**
 * @file c_cockpit_router.h
 * @author 
 * @brief 
 * @version 1.0
 * @date 2023-12-04
 * 
 * 
 * 
 */
#ifndef C_COCKPIT_ROUTER_H
#define C_COCKPIT_ROUTER_H

#include <ctime>
#include <chrono>
#include <time.h>
#include <mutex>
#include <string.h>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <uuid/uuid.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <omp.h>

#include "my_typedef.h"
#include "config_io.h"
#include "easylogging++.h"
#include "utils.h"
#include "openssl_code.h"
#include "mine_rds.pb.h"

#include "ros/ros.h"
#include "ros/time.h"
#include "std_msgs/String.h"

#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Imu.h>
#include <nav_msgs/Odometry.h>

namespace n_cockpit_router
{

class CCockpitRouter
{
private:
    ros::NodeHandle node_handle_;

    ros::Subscriber v_command_sub_;
    ros::Subscriber v_imu_sub_;
    ros::Subscriber v_odom_sub_;
    geometry_msgs::Twist state;
    sensor_msgs::Imu imu;
    nav_msgs::Odometry odom;

    ros::Publisher router_command_pub_;
    geometry_msgs::Twist cmd;

    /* init */
    std::mutex lock_;
    std::string cockpitIp_;
    int32 cockpitPort_;
    int32 localId_;
    int32 localPort_;
    int32 cockpitSocket_;
    int32 localSocket_;
    int32 udpSendCycle_;
    int32 udpSendLogin_;
    int32 udpRecvCycle_;
    int32 udpRecvTimeout_;
    std::string key_;
    int32 method_;
    double rosTimeS_;
    double rosTimeNs_;

    /* publishCommandToV */
    bool publishStatus_;

    /* recvServerMessage */

    /* sendServerMessage */
    bool sendNeedStates_;
    bool sendHeart_;
    int64 timestamp_;

public:
    CCockpitRouter();
    ~CCockpitRouter();
    
    /**
     * @brief program init
     * config ROS UDP
     */
    void init();

    void receiveCommandCallBack(const geometry_msgs::Twist::ConstPtr& msg);

    void receiveImuCallBack(const sensor_msgs::Imu::ConstPtr& msg);

    void receiveOdomCallBack(const nav_msgs::Odometry::ConstPtr& msg);

    /* ------------------------------------------------------------------------- */

    /**
     * @brief publish command to vehicle
     * 
     */
    void publishCommandToV();

    /**
     * @brief receive message from server
     * 
     */
    void recvCockpitMessage();

    /**
     * @brief send message to server
     * 
     */
    void sendCockpitMessage();

    /* ------------------------------------------------------------------------- */

    /**
     * @brief analyze command
     * 
     * @param data_source 
     * @param data_length 
     * @return true 
     * @return false 
     */
    bool analyzeRemoteCommand(std::string data_source, const int32 data_length);

    /**
     * @brief pack states
     * 
     * @param buffer 
     * @return int16 
     */
    int16 packStatesInfo(uint8 *buffer);
    
}; // class CCockpitRouter

} // namespace n_cockpit_router

#endif
