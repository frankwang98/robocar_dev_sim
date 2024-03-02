/**
 * @file c_info_router.cpp
 * @author 
 * @brief 
 * @version 1.0
 * @date 2023-12-04
 * 
 * 
 * 
 */

#include "c_cockpit_router.h"

const bool DEBUG = 0; // 调试模式下，车辆状态用模拟数据

namespace n_cockpit_router
{

CCockpitRouter::CCockpitRouter()
{
    cmd.linear.x = 0.0;
    cmd.angular.z = 0.0;
    sendNeedStates_ = true;
}

CCockpitRouter::~CCockpitRouter() {}

void CCockpitRouter::init()
{
    /* read config - n_info_router.ini */
    using hivelab_config_io::Config;
    Config::UseDefaultPath("n_info_router.ini");

    cockpitIp_ = Config::Get<std::string>("COCKPIT_NET", "IP");
    cockpitPort_ = Config::Get<int32>("COCKPIT_NET", "PORT");

    udpSendCycle_ = Config::Get<int32>("LOCAL_NET", "UDP_SEND_CYCLE_MS");
    udpSendLogin_ = Config::Get<int32>("LOCAL_NET", "UDP_SEND_LOGIN_MS");
    udpRecvCycle_ = Config::Get<int32>("LOCAL_NET", "UDP_RECV_CYCLE_MS");
    udpRecvTimeout_ = Config::Get<int32>("LOCAL_NET", "UDP_RECV_TIMEOUT_MS");

    key_ = Config::Get<std::string>("ENCRYPTION", "KEY_CODE");
    method_ = Config::Get<int32>("ENCRYPTION", "METHOD_CODE");

    /* ROS param setup */
    ros::NodeHandle nh("~");
    nh.param("local_port", localPort_, 8881);
    nh.param("local_id", localId_, 1001);

    router_command_pub_ = node_handle_.advertise<geometry_msgs::Twist>("cmd_vel", 1000);

    v_command_sub_ = node_handle_.subscribe("cmd_vel", 5000, &CCockpitRouter::receiveCommandCallBack, this);
    v_imu_sub_ = node_handle_.subscribe("imu", 5000, &CCockpitRouter::receiveOdomCallBack, this);
    v_odom_sub_ = node_handle_.subscribe("odom", 5000, &CCockpitRouter::receiveOdomCallBack, this);

    LOG(INFO) << "ROS Publisher and Subscriber set up!";

    /* UDP setup - receive dmms and road */
    cockpitSocket_ = UdpServerInit(localPort_);
    localSocket_ = UdpClientInit();
    LOG(INFO) << "IDS socket id: " << cockpitSocket_ << " ADS socket id: " << localSocket_;

    LOG(INFO) << "RDS(Remote Driving System) address: " << cockpitIp_ <<":" << cockpitPort_;
    LOG(INFO) << "ADS(Autonomous Driving System) address: "<< localId_ << ":" << localPort_;
}

void CCockpitRouter::receiveCommandCallBack(const geometry_msgs::Twist::ConstPtr& msg)
{
    // 将接收到的 Twist 消息打印出来
    // LOG(INFO) << "Received linear velocity: " << msg->linear.x << ", angular velocity: " << msg->angular.z;
    state.linear.x = msg->linear.x;
    state.angular.z = msg->angular.z;
}

void CCockpitRouter::receiveImuCallBack(const sensor_msgs::Imu::ConstPtr& msg)
{
    // 实际机器人状态用哪个待确认
    // LOG(INFO) << "Received linear: " << msg->orientation.x << ", angular: " << msg->orientation.z;
    imu.orientation.x = msg->orientation.x;
    imu.orientation.z = msg->orientation.z;
}

void CCockpitRouter::receiveOdomCallBack(const nav_msgs::Odometry::ConstPtr& msg)
{
    // LOG(INFO) << "Received odom x: " << msg->pose.pose.position.x << ", y: " << msg->pose.pose.position.y
    //           << ", theta: " << msg->pose.pose.orientation.z;
    odom.pose.pose.position.x = msg->pose.pose.position.x;
    odom.pose.pose.position.y = msg->pose.pose.position.y;
    odom.pose.pose.orientation.z = msg->pose.pose.orientation.z;
}

void CCockpitRouter::publishCommandToV()
{
    std::lock_guard<std::mutex> guard(lock_);
    if (DEBUG)
    {
        publishStatus_ = 1;
        cmd.linear.x = 1.0;
        cmd.angular.z = 1.0;
    }

    if (publishStatus_)
    {
        router_command_pub_.publish(cmd);
        LOG(INFO) << "Send linear velocity: " << cmd.linear.x << ", angular velocity: " << cmd.angular.z;

        publishStatus_ = false;

        // LOG(INFO) << COLOR_YELLOW << "===== 已发布路由信息! Stop send!" << COLOR_RESET;
    }
    else
    {
        /* 安全措施 */
        cmd.linear.x = 0.0;
        cmd.angular.z = 0.0;

        router_command_pub_.publish(cmd);
        publishStatus_ = false;
        // LOG(INFO) << COLOR_YELLOW << "===== 未发布路由信息! Continue send!" << COLOR_RESET;
    }
}

void CCockpitRouter::recvCockpitMessage()
{
    uint8 serverBuffer[999999];
    memset(serverBuffer, '0', sizeof(serverBuffer));
    std::string recvMessage;

    /* follow ros to termination */
    while (ros::ok())
    {
        int32 length = 0;
        if ((length = ListenMessage(cockpitSocket_, serverBuffer)) > 0)
        {
#pragma omp parallel for
            for (int i = 0; i < length; i++)
            {
                recvMessage = recvMessage + (char)serverBuffer[i];
            }
        }
        else
        {
            // LOG(INFO)<<"===== 未收到座舱消息,等待中 =====";
        }
        LOG(INFO) << "recvMessage size: " << recvMessage.size();

        analyzeRemoteCommand(recvMessage, recvMessage.size());
        
        recvMessage = "";
        usleep(udpRecvCycle_ * 1000);
    }
}

void CCockpitRouter::sendCockpitMessage()
{
    uint8 statesBuffer[1000];

    memset(statesBuffer, 0, sizeof(statesBuffer));

    /* follow ros to termination */
    while (ros::ok())
    {
        uint32 statesLength = 0;

        if (true == sendNeedStates_)
        {
            statesLength = packStatesInfo(statesBuffer);
            SendMessage(cockpitSocket_, cockpitIp_.c_str(), cockpitPort_, statesBuffer, statesLength);
        }

        usleep(udpSendCycle_ * 1000);
    }
}

bool CCockpitRouter::analyzeRemoteCommand(std::string data_source, const int32 data_length)
{
    if (data_length < 1)
    {
        return false;
    }

    std::string data_source_code = decrypt(data_source, key_, method_);

    robocar_rds::Protocol protobuf;
    if (!protobuf.ParseFromString(data_source_code))
    {
        LOG(INFO) << "command解析请求失败(Failed to parse request)";
    }
    else
    {
        robocar_rds::RdsMessage rds_message = protobuf.rds_message();

        LOG(INFO) << "===== 接收座舱指令中 =====";
        LOG(INFO) << "===== 车辆控制  线速度: " << rds_message.linear_x()
                    << " 角速度: " << rds_message.angular_z();
        
        cmd.linear.x = rds_message.linear_x();
        cmd.angular.z = rds_message.angular_z();

        publishStatus_ = true;
    }
    return true;
}

int16 CCockpitRouter::packStatesInfo(uint8* buffer)
{
    // 测试msg_v_state，模拟位置
    if (DEBUG)
    {
        state.linear.x = 1.0;
        state.angular.z = 2.0;
    }

    robocar_rds::Protocol protocol;
    robocar_rds::VehMessage *veh_message;

    veh_message = protocol.mutable_veh_message();
    // veh_message->set_linear_x(state.linear.x);
    // veh_message->set_angular_z(state.angular.z);

    // odom state
    veh_message->set_linear_x(odom.pose.pose.position.x);
    veh_message->set_angular_z(odom.pose.pose.orientation.z);

    std::string msg_data;
    protocol.SerializeToString(&msg_data);

    std::string message_proto = protocol.DebugString();
    LOG(INFO) << "state protobuf result: " << message_proto;

    std::string msg_data_code = encrypt(msg_data, key_, method_);
    int32 msg_length = msg_data_code.length();
    memcpy(buffer, (char *)msg_data_code.c_str(), msg_length);
    return msg_length;
}

} // namespace n_cockpit_router
