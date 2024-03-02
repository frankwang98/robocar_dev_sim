#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <fstream>
#include <sstream>
#include <type_traits>
#include <functional>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>
#include <errno.h>
#include <assert.h>
#include <stdexcept>
#include <array>
#include <regex>
#include <uuid/uuid.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/**
 * @brief Get the Uuid Str object
 * 
 * @return std::string 
 */
std::string getUuidStr();

/**
 * @brief Get the Time Millis object
 * 
 * @return long 
 */
long getTimeMillis();

/**
 * @brief 获取ping延迟值
 * @return ping_time
*/
int getPingTime(const std::string& ipAddress);

/**
 * @brief UDP服务端初始化
 * @param port 监听端口
 * @return socket_id
*/
int UdpServerInit(const int port);

/**
 * @brief UDP客户端初始化
 * @return socket_id
*/
int UdpClientInit();

/**
 * @brief 消息监听函数
 * @param socket_id socket描述符
 * @param data 数据
 * @return data_len
*/
int ListenMessage(const int socket_id, unsigned char *data);

/**
 * @brief 消息发送函数
 * @param socket_id socket描述符
 * @param ip ip地址
 * @param port 端口
 * @param data 数据
 * @param data_len 数据长度
*/
bool SendMessage(const int socket_id, const char *ip, const int port, unsigned char *data, unsigned int data_len);

/**
 * @brief UDP组播接收
 * 
 * @param multicast_group 
 * @param port 
 * @return int 
 */
int udpMulticastServerRecv(std::string multicast_group, int port);

#endif
