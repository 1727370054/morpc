#ifndef __LOGGER_H__
#define __LOGGER_H__

/*
 *  morpc框架日志类
 */

#include "asyn_queue.h"

#include <string>
#include <fstream>
#include <sstream>

namespace morpc
{
    enum LogLevel
    {
        DEBUG,
        INFO,
        ERROR
    };

    class Logger
    {
    public:
        ~Logger() {}

        static Logger &GetInstance()
        {
            static Logger log;
            return log;
        }

        /// @brief 设置日志级别(默认INFO)
        void SetLogLevel(LogLevel level);

        /// @brief 写日志
        void WriteLog(LogLevel level, std::string message, const char *filename, int line);

        /// @brief 退出写日志线程
        void Exit() { exit_ = true; }

        /// @brief 设置日志是否输出到控制台,  默认是输出
        void set_output_console(bool output_console) { output_console_ = output_console; }

    private:
        Logger();
        Logger(const Logger &) = delete;
        Logger &operator=(const Logger &) = delete;

        /// @brief 线程入口函数
        void Main();

    private:
        LogLevel loglevel_ = INFO;
        AsynQueue<std::string> asyn_queue_;
        bool exit_ = false;
        /// @brief 写日志文件流
        std::ofstream ofs_;
        bool output_console_ = true;
    };

    void Log(LogLevel level, std::string message, const char *filename, int line);
}

#define LOG_DEBUG(message) morpc::Log(morpc::LogLevel::DEBUG, message, __FILE__, __LINE__)
#define LOG_INFO(message) morpc::Log(morpc::LogLevel::INFO, message, __FILE__, __LINE__)
#define LOG_ERROR(message) morpc::Log(morpc::LogLevel::ERROR, message, __FILE__, __LINE__)

#endif