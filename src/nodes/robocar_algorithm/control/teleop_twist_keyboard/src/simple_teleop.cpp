#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <termios.h>
#include <signal.h>

int kfd = 0;
struct termios cooked, raw;

void keyboardCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
    // 将接收到的 Twist 消息打印出来
    ROS_INFO("Received v: %f, w: %f",
             msg->linear.x, msg->angular.z);
}

void quit(int sig)
{
    // 恢复终端设置
    tcsetattr(kfd, TCSANOW, &cooked);
    ros::shutdown();
    exit(0);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "simple_teleop");
    ros::NodeHandle nh;

    std::cout << "Reading from keyboard..." << std::endl;

    // 订阅键盘输入的 Twist 消息
    ros::Subscriber sub = nh.subscribe("cmd_vel", 1, keyboardCallback);

    // 发布 Twist 消息到 cmd_vel 主题
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1);

    // 设置终端输入模式
    tcgetattr(kfd, &cooked);
    memcpy(&raw, &cooked, sizeof(struct termios));
    raw.c_lflag &= ~(ICANON | ECHO);
    raw.c_cc[VEOL] = 1;
    raw.c_cc[VEOF] = 2;
    tcsetattr(kfd, TCSANOW, &raw);

    // 注册中断信号处理函数
    signal(SIGINT, quit);

    // 创建 Twist 消息
    geometry_msgs::Twist cmd;
    cmd.linear.x = 0.0;
    cmd.angular.z = 0.0;

    // 控制循环
    while (ros::ok())
    {
        // 读取键盘输入
        char c;
        if (read(kfd, &c, 1) < 0)
        {
            perror("read():");
            exit(-1);
        }

        // 根据键盘输入设置线速度和角速度
        switch (c)
        {
            case 'w':
                cmd.linear.x = 0.5;
                break;
            case 's':
                cmd.linear.x = -0.5;
                break;
            case 'a':
                cmd.angular.z = 0.5;
                break;
            case 'd':
                cmd.angular.z = -0.5;
                break;
            case '+':
                cmd.linear.x += 0.5;
                break;
            case '-':
                cmd.linear.x -= 0.5;
                break;
            case '[':
                cmd.angular.z += 0.5;
                break;
            case ']':
                cmd.angular.z -= 0.5;
                break;
            case 'e':
            {
                cmd.linear.x = 0;
                cmd.angular.z = 0;
                std::cout << "EStop!" << std::endl;
                break;
            }    
            default:
                break;
        }

        // 发布 Twist 消息
        pub.publish(cmd);

        // 重置线速度和角速度为零
        // cmd.linear.x = 0.0;
        // cmd.angular.z = 0.0;

        ros::spinOnce();
    }

    // 恢复终端设置
    tcsetattr(kfd, TCSANOW, &cooked);

    return 0;
}