#ifndef MY_TYPE_DEF_H
#define MY_TYPE_DEF_H

typedef char int8;
typedef short int16;
typedef int int32;
typedef long int64;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long uint64;

typedef float float32;
typedef double float64;

// 定义颜色转义序列（刷色）
// Usage: std::cout << COLOR_RED << "红色文本" << COLOR_RESET << std::endl;
#define COLOR_RED     "\033[31m" // 红 错误警告
#define COLOR_GREEN   "\033[32m" // 绿 运行情况
#define COLOR_YELLOW  "\033[33m" // 黄 后台消息
#define COLOR_BLUE    "\033[34m" // 蓝 车端消息
#define COLOR_MAGENTA "\033[35m" // 洋红
#define COLOR_CYAN    "\033[36m" // 青
#define COLOR_RESET   "\033[0m"  // 复位
#define COLOR_BOLD    "\033[1m"  // 加粗/高亮
#define COLOR_UDLINE  "\033[4m"  // 下划线
#define COLOR_REVERSE "\033[7m"  // 反转前景色(30-37)和背景色(40-47)

#endif  // MY_TYPE_DEF_H
