#ifndef HELLO_LOG_H
#define HELLO_LOG_H

#include "spdlog/spdlog.h"
#include <sinks/rotating_file_sink.h>
#include "spdlog/sinks/stdout_color_sinks.h"

extern bool spdlog_init_flag;
extern std::shared_ptr<spdlog::sinks::stdout_color_sink_st> console_sink;
extern std::shared_ptr<spdlog::sinks::rotating_file_sink_st> file_sink;
extern std::shared_ptr<spdlog::logger> hellocpp_logger;

inline void init_logger()
{
    std::vector<spdlog::sink_ptr> sinks;
    console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_st>();
    // Create a file rotating logger with 5 MB size max and 10 rotated files
    auto max_size = 1048576 * 5;
    auto max_files = 10;
    file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_st>("logs/hellocpp.log", max_size, max_files);
    console_sink->set_level(spdlog::level::info);
    file_sink->set_level(spdlog::level::debug);

    sinks.push_back(console_sink);
    sinks.push_back(file_sink);

    hellocpp_logger = std::make_shared<spdlog::logger>(spdlog::logger("multi_sink", sinks.begin(), sinks.end()));
    hellocpp_logger->set_level(spdlog::level::debug);
}

inline void hellocpp_log(const string &log_level, const string &log_content)
{
    if (spdlog_init_flag)
    {
        init_logger();
        spdlog_init_flag = false;
    }

    if (log_level == "INFO")
    {
        // "this message should not appear in the console, only in the file."
        hellocpp_logger->info(log_content);
    }
    else if (log_level == "DEBUG")
    {
        hellocpp_logger->debug(log_content);
    }
    else if (log_level == "WARN")
    {
        // "this should appear in both console and file"
        hellocpp_logger->warn(log_content);
    }
    else if (log_level == "ERROR")
    {
        hellocpp_logger->error(log_content);
    }
}

#endif
