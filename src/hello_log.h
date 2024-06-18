#ifndef HELLO_LOG_H
#define HELLO_LOG_H

#include "spdlog/spdlog.h"
#include <sinks/rotating_file_sink.h>
#include "spdlog/sinks/stdout_color_sinks.h"

class HiSpdlog;

// hi_spdlog instance is defined in main.cpp
extern HiSpdlog hi_spdlog;

class HiSpdlog
{
public:
    HiSpdlog(const string &logger_name = "hi_spdlog", const string &log_path = "logs/hellocpp.log", unsigned int max_log_size = 1048576 * 5, unsigned int max_log_files = 10)
        : console_sink(std::make_shared<spdlog::sinks::stdout_color_sink_st>()),
          file_sink(std::make_shared<spdlog::sinks::rotating_file_sink_st>(log_path, max_log_size, max_log_files)),
          hi_logger(std::make_shared<spdlog::logger>(spdlog::logger(logger_name, {console_sink, file_sink})))
    {
        console_sink->set_level(spdlog::level::info);
        file_sink->set_level(spdlog::level::debug);
        hi_logger->set_level(spdlog::level::debug);
    }


    // 当你调用set_level函数并为它提供一个日志级别参数时，你实际上是在指定该日志记录器（logger或sink）应该记录哪些级别的日志消息。
    // 例如，如果你将日志级别设置为warn，那么只有警告、错误和致命错误级别的日志消息会被记录，而较低级别的消息（如调试和信息）则会被忽略。
    // 日志级别如下（数字越大，级别越高）：
    // #define SPDLOG_LEVEL_TRACE 0
    // #define SPDLOG_LEVEL_DEBUG 1
    // #define SPDLOG_LEVEL_INFO 2
    // #define SPDLOG_LEVEL_WARN 3
    // #define SPDLOG_LEVEL_ERROR 4
    // #define SPDLOG_LEVEL_CRITICAL 5
    // #define SPDLOG_LEVEL_OFF 6

    inline void pls_log(const string &log_level, const string &log_content)
    {
        if (log_level == "INFO")
        {
            hi_logger->info(log_content);
        }
        else if (log_level == "DEBUG")
        {
            hi_logger->debug(log_content);
        }
        else if (log_level == "WARN")
        {
            // "this should appear in both console and file"
            hi_logger->warn(log_content);
        }
        else if (log_level == "ERROR")
        {
            hi_logger->error(log_content);
        }
    }

private:
    std::shared_ptr<spdlog::sinks::stdout_color_sink_st> console_sink;
    std::shared_ptr<spdlog::sinks::rotating_file_sink_st> file_sink;
    std::shared_ptr<spdlog::logger> hi_logger;
};



#endif
