/**
 * @file n_info_router.cpp
 * @author 
 * @brief 
 * @version 1.0
 * @date 2023-12-04
 * 
 * 
 * 
 */

#include "c_cockpit_router.h"

#include <pthread.h>

/* easyloggingpp init */
#define ELPP_THREAD_SAFE
INITIALIZE_EASYLOGGINGPP

#ifndef SETUP_DEFAULT_EASYLOGGINGPP
#define SETUP_DEFAULT_EASYLOGGINGPP_3(config_file, rolloutHandler, file_name) {  \
   el::Loggers::addFlag(el::LoggingFlag::StrictLogFileSizeCheck);   \
   el::Configurations conf(config_file);                            \
   conf.set(el::Level::Info, el::ConfigurationType::Filename, file_name);    \
   el::Loggers::reconfigureLogger("default", conf);                 \
   el::Helpers::installPreRollOutCallback(rolloutHandler);          \
} 
#define SETUP_DEFAULT_EASYLOGGINGPP(config_file, rolloutHandler) {  \
   el::Loggers::addFlag(el::LoggingFlag::StrictLogFileSizeCheck);   \
   el::Configurations conf(config_file);                            \
   el::Loggers::reconfigureLogger("default", conf);                 \
   el::Helpers::installPreRollOutCallback(rolloutHandler);          \
} 
#endif

/* constant */
const int ROS_RATE = 50;

namespace ncr = n_cockpit_router;

int printThreadFail(std::string info);
void* threadRosCockpitMessage(void* arg);
void* threadRecvCockpitMessage(void* arg);
void* threadSendCockpitMessage(void* arg);

void rolloutHandler(const char* filename, std::size_t size);

int main(int argc, char** argv)
{
    ros::init(argc, argv, "n_info_router");

    if (argc > 1)
    {
        /* add log's direction argument */
        std::string file_name = std::string("./log/") + argv[1] + "/router_info.log";
        SETUP_DEFAULT_EASYLOGGINGPP_3("src/config/logger.conf", rolloutHandler, file_name);
    }
    else
    {
        SETUP_DEFAULT_EASYLOGGINGPP("src/config/logger.conf", rolloutHandler);
    }

    ncr::CCockpitRouter cockpit_router;
    cockpit_router.init();

    pthread_t thread_ros_cockpit_message;
    if(pthread_create(&thread_ros_cockpit_message, NULL, threadRosCockpitMessage, (void*)&cockpit_router))
    {
        return printThreadFail("threadRosCockpitMessage");
    }

    pthread_t thread_recv_cockpit_message;
    if(pthread_create(&thread_recv_cockpit_message, NULL, threadRecvCockpitMessage, (void*)&cockpit_router))
    {
        return printThreadFail("threadRecvCockpitMessage");
    }

    pthread_t thread_send_cockpit_message;
    if(pthread_create(&thread_send_cockpit_message, NULL, threadSendCockpitMessage, (void*)&cockpit_router))
    {
        return printThreadFail("threadSendCockpitMessage");
    }

    pthread_join(thread_ros_cockpit_message, NULL);
    pthread_join(thread_send_cockpit_message, NULL);

    return 0;
}

/**
 * @brief communicate with car through ROS1
 * ROS's rate : 50Hz
 * @param arg 
 * @return void* 
 */
void* threadRosCockpitMessage(void* arg)
{
    LOG(INFO) << COLOR_YELLOW << "Thread threadRosCockpitMessage " << COLOR_GREEN << "ok" << COLOR_RESET;
    ncr::CCockpitRouter* cockpit_router = (ncr::CCockpitRouter*)arg;
    ros::Rate loop_rate(ROS_RATE);
    while(ros::ok())
    {
        cockpit_router->publishCommandToV();
        ros::spinOnce();
        loop_rate.sleep();
    }
    LOG(INFO) << COLOR_RED << "Thread threadRosCockpitMessage " << COLOR_GREEN << "ok" << COLOR_RESET;
    return 0;
}

/**
 * @brief receive cockpit command through UDP
 * 100Hz
 * @param arg 
 * @return void* 
 */
void* threadRecvCockpitMessage(void* arg)
{
    LOG(INFO) << COLOR_YELLOW << "Thread threadRecvCockpitMessage " << COLOR_GREEN << "ok" << COLOR_RESET;
    ncr::CCockpitRouter* cockpit_router = (ncr::CCockpitRouter*)arg;
    cockpit_router->recvCockpitMessage();
    LOG(INFO) << COLOR_RED << "Thread threadRecvCockpitMessage " << COLOR_GREEN << "ok" << COLOR_RESET;
    return 0;
}

/**
 * @brief send car_info to cockpit through UDP  
 * 10Hz
 * @param arg 
 * @return void* 
 */
void* threadSendCockpitMessage(void* arg)
{
    LOG(INFO) << COLOR_YELLOW << "Thread threadSendCockpitMessage " << COLOR_GREEN << "ok" << COLOR_RESET;
    ncr::CCockpitRouter* cockpit_router = (ncr::CCockpitRouter*)arg;
    cockpit_router->sendCockpitMessage();
    LOG(INFO) << COLOR_RED << "Thread threadSendCockpitMessage " << COLOR_GREEN << "ok" << COLOR_RESET;
    return 0;
}

/**
 * @brief print fail info
 * common
 * @param info 
 * @return int 
 */
int printThreadFail(std::string info)
{
    ROS_INFO("%s thread creation failed!", info.c_str());
    return 0;
}

/**
 * @brief print log file
 * 
 * @param filename 
 * @param size 
 */
void rolloutHandler(const char* filename, std::size_t size)
{
    time_t t = time(NULL);
    char time_str[64] = {0};
    // 给日志加上时间后缀
    strftime(time_str, sizeof(time_str) - 1, "_%Y_%m_%d_%H_%M_%S", localtime(&t));
    std::string str(filename);
    std::stringstream ss;
    ss << "mv " << filename << " "
       << str.substr(0, str.length() - 4) /*去掉“.log”后缀*/ << time_str << ".log";
    int ret = std::system(ss.str().c_str());
    std::cout << "rolloutHandler return: " << ret << std::endl;
}

