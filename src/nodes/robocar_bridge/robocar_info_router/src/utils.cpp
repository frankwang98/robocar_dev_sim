#include "utils.h"

std::string getUuidStr()
{
    uuid_t uuid;
    char uuidStr[37];
    uuid_generate(uuid);
    uuid_unparse_lower(uuid, uuidStr);
    return uuidStr;
}

long getTimeMillis()
{
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto duration = currentTime.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

int getPingTime(const std::string& ipAddress)
{
    std::string command = "ping -c 1 " + ipAddress;
    std::array<char, 128> buffer;
    std::ostringstream result;

    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        throw std::runtime_error("Failed to execute the ping command.");
    }

    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result << buffer.data();
    }

    pclose(pipe);

    std::string pingOutput = result.str();

    // 使用正则表达式匹配延迟信息
    std::regex pattern("time=(\\d+)");
    std::smatch match;
    if (std::regex_search(pingOutput, match, pattern)) {
        std::string delayStr = match[1].str();
        int delay = std::stoi(delayStr);
        return delay;
    } else {
        // throw std::runtime_error("Failed to get the ping delay.");
        return -1;
    }
}

int UdpServerInit(const int port)
{
    sockaddr_in addr;
    int socket_id;
    socket_id = socket(AF_INET, SOCK_DGRAM, 0);
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);
    bind(socket_id, (struct sockaddr *)&addr, sizeof(addr)); // Server need bind

    /* 设置接收超时 */
    timeval tv = {0, 200 * 1000}; // configurable，当前配置为200ms，第一个参数为s，第二个参数为us
    if (0 != setsockopt(socket_id, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(timeval)))
    {
        printf("setsockopt timeval error: %s\n", strerror(errno));
    }

    /* 设置端口复用 */
    int reuse = 1; // allows multiple sockets to be bound to the same address and port
    if (0 != setsockopt(socket_id, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)))
    {
        printf("setsockopt reuse error: %s\n", strerror(errno));
    }

    return socket_id;
}

int UdpClientInit()
{
    int socket_id;
    socket_id = socket(AF_INET, SOCK_DGRAM, 0);

    return socket_id;
}

int ListenMessage(const int socket_id, unsigned char *data)
{
    char source_ip[INET_ADDRSTRLEN];
    sockaddr_in source_addr_;
    int data_length;
    socklen_t sockadd_length;
    sockadd_length = sizeof(sockaddr_in);
    data_length = recvfrom(socket_id, data, 300000, MSG_WAITALL, (struct sockaddr *)&source_addr_, &sockadd_length);

    /* inet_ntoa和inet_ntop都是将ip从二进制转为字符串，由于inet_ntoa会覆盖静态缓冲区，因此建议在多线程或异步环境中使用inet_ntop */
    std::string recv_ip = inet_ntop(AF_INET, &source_addr_.sin_addr, source_ip, sizeof(source_ip));

    return data_length;
}

bool SendMessage(const int socket_id, const char *ip, const int port, unsigned char *data, unsigned int data_len)
{
    sockaddr_in addr; // socket struct
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;            // 设置协议族
    addr.sin_addr.s_addr = inet_addr(ip); // 接收端 ip
    addr.sin_port = htons(port);          // 接收端 port

    /* Check the return value to determine whether the transmission was successful */
    if (-1 == sendto(socket_id, data, data_len, 0, (struct sockaddr *)&addr, sizeof(addr)))
    {
        std::cout << "SendMessage strerror: " << strerror(errno) << std::endl;
        return false;
    }
    return true;
}

int udpMulticastServerRecv(std::string multicast_group, int port)
{
    int socket_id;
    socket_id = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in local_addr{};
    memset(&local_addr, 0, sizeof(local_addr));
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(port);
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(socket_id, (struct sockaddr *)&local_addr, sizeof(local_addr)) < 0)
    {
        std::cerr << "Failed to bind." << std::endl;
        return -1;
    }

    /* 设置组播TTL（Time-To-Live） */ 
    int ttl = 1; // 默认情况下，数据包只能在本地网络传递
    if (setsockopt(socket_id, IPPROTO_IP, IP_MULTICAST_TTL, (void *)&ttl, sizeof(ttl)) < 0)
    {
        std::cerr << "Failed to set TTL." << std::endl;
        return -1;
    }

    /* 设置组播组信息 */ 
    struct sockaddr_in multicast_addr{};
    memset(&multicast_addr, 0, sizeof(multicast_addr));
    multicast_addr.sin_family = AF_INET;
    multicast_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, multicast_group.c_str(), &(multicast_addr.sin_addr)) <= 0)
    {
        std::cerr << "Invalid multicast group address." << std::endl;
        return -1;
    }

    /* 加入组播组 */ 
    struct ip_mreq mreq{};
    mreq.imr_multiaddr.s_addr = inet_addr(multicast_group.c_str());
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);
    if (setsockopt(socket_id, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *)&mreq, sizeof(mreq)) < 0)
    {
        std::cerr << "Failed to join multicast group." << std::endl;
        return -1;
    }

    return socket_id;
}
