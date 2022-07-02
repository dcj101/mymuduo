#pragma once

#include "noncopyable.h"

#include <cstring>
#include <iostream>
#include <string>

// 定义日志的级别 INFO ERROR(错误信息，但是不影响程序执行) FATAL(严重错误) DEBUG (调试信息)
enum LogLevel 
{
    INFO,
    ERROR,
    FATAL,
    DEBUG
};

// 定义宏 LOG_INFO("%s %d\n", ...)
// ##__VA_ARGS__ 任意参数的宏
#define LOG_INFO(LogmsgFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance(); \
        logger.setLogLevel(INFO); \
        char buf[1024] = {0}; \
        snprintf(buf,1024,LogmsgFormat,##__VA_ARGS__); \
        logger.log(buf); \
    } while(0); 

#define LOG_ERROR(LogmsgFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance(); \
        logger.setLogLevel(ERROR); \
        char buf[1024] = {0}; \
        snprintf(buf,1024,LogmsgFormat,##__VA_ARGS__); \
        logger.log(buf); \
    } while(0); 

#define LOG_FATAL(LogmsgFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance(); \
        logger.setLogLevel(FATAL); \
        char buf[1024] = {0}; \
        snprintf(buf,1024,LogmsgFormat,##__VA_ARGS__); \
        logger.log(buf); \
    } while(0); 

#ifdef DEBUG
#define LOG_DEBUG(LogmsgFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance(); \
        logger.setLogLevel(DEBUG); \
        char buf[1024] = {0}; \
        snprintf(buf,1024,LogmsgFormat,##__VA_ARGS__); \
        logger.log(buf); \
    } while(0);
// 为了防止宏定义出错一般都是do_while结构
#else 
    #define LOG_DEBUG(LogmsgFormat, ...)
#endif
// 输出一个日志类
class Logger : noncopyable
{
public:
    //获取日志唯一的实例对象
    static Logger& instance();
    //设置日志级别
    void setLogLevel(int Level);
    // 写日志
    void log(std::string msg);
private:
    int logLevel_; // 后面有个下划线
    Logger(){}
}; 