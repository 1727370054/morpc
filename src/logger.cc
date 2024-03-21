#include "logger.h"
#include "morpc_util.h"

#include <time.h>
#include <thread>
#include <iostream>
#include <sstream>

namespace morpc
{
    Logger::Logger()
    {
        // 启动写日志线程
        std::thread writeLogTask(&Logger::Main, this);

        writeLogTask.detach();
    }

    void Logger::Main()
    {
        // 获取当前日期, 然后取日志信息写入到相应的日志文件当中
        while (!exit_)
        {
            time_t now = time(nullptr);
            tm *nowtm = localtime(&now);

            char filename[128];
            sprintf(filename, "%d-%d-%d-log.txt", nowtm->tm_year + 1900, nowtm->tm_mon + 1, nowtm->tm_mday);
            ofs_.open(filename, std::ios::out | std::ios::app);
            if (!ofs_.is_open())
            {
                std::cerr << "logger file: " << filename << " open failed!" << std::endl;
                exit(EXIT_FAILURE);
            }

            std::string msg = asyn_queue_.Pop();
            ofs_.write(msg.c_str(), msg.size());

            ofs_.close();
        }
    }

    void Logger::SetLogLevel(LogLevel level)
    {
        loglevel_ = level;
    }

    void Logger::WriteLog(LogLevel level, std::string message, const char *filename, int line)
    {
        if (level < loglevel_)
            return;

        std::string log_str = "DEBUG";

        switch (level)
        {
        case DEBUG:
            log_str = "DEBUG";
            break;
        case INFO:
            log_str = "INFO";
            break;
        case ERROR:
            log_str = "ERROR";
            break;
        default:
            break;
        }

        std::string log_time = GetCurTime(0, "%F %T");
        std::stringstream log_txt;
        log_txt << log_time << " - [" << log_str << "] " << filename
                << "<line:" << line << "> \n";
        log_txt << message << "\n";

        if (output_console_)
        {
            std::cout << log_txt.str() << std::endl;
        }

        asyn_queue_.Push(log_txt.str());
    }

    void Log(LogLevel level, std::string message, const char *filename, int line)
    {
        Logger::GetInstance().WriteLog(level, message, filename, line);
    }
}