/*
 * @Author: 熊义 JassimXiong@gmail.com
 * @Date: 2023-07-14 11:15:16
 * @LastEditors: xiongyi jassimxiong@gmail.com
 * @LastEditTime: 2023-12-14 14:31:22
 * @FilePath: /cpp_demo/src/app/common/logger.h
 * @Description: 如果export debug=on，则打开调试日志
 *
 * Copyright (c) 2023 xxxx, 版权所有
 */

#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "make_unique.h"
#include "singleton.h"

#include "spdlog/async.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

#include <memory>
#include <stdexcept>

#define LOG_TOPIC "app"                              // 日志tag
#define LOG_FILE_NAME "./log/" LOG_TOPIC ".log"      // 日志文件名
#define LOG_FILE_SIZE 1024 * 1024 * 3                // 3MB
#define LOG_ROTATION 3                               // 日志文件满3个时开始滚动日志
#define LOG_FLUSH_ON spdlog::level::info             // 当打印这个级别日志时flush
#define PATTERN "[%Y-%m-%d %H:%M:%S.%f] [%^%L%$] %v" // 日志样式

#define LOGE(...) Singleton<Logger>::instance().log_error(__VA_ARGS__)
#define LOGW(...) Singleton<Logger>::instance().log_warn(__VA_ARGS__)
#define LOGI(...) Singleton<Logger>::instance().log_info(__VA_ARGS__)
#define LOGD(...) Singleton<Logger>::instance().log_debug(__VA_ARGS__)
#define LOGC(...) Singleton<Logger>::instance().log_critical(__VA_ARGS__)
class Logger {
private:
    std::unique_ptr<spdlog::logger> logger_;

private:
    bool is_debug_mode() {
        char *var = getenv("debug");
        if (nullptr == var) {
            return false;
        }
        if (0 == strcmp(var, "on")) {
            return true;
        }
        return false;
    }

public:
    Logger() {
        auto function = [&]() {
            auto stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
            auto rotating_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
                LOG_FILE_NAME, LOG_FILE_SIZE, LOG_ROTATION);
            std::vector<spdlog::sink_ptr> sinks{ stdout_sink, rotating_sink };
            logger_ = std::make_unique<spdlog::logger>(LOG_TOPIC, sinks.begin(), sinks.end());
            logger_->set_pattern(PATTERN);
            if (is_debug_mode()) {
                logger_->set_level(spdlog::level::debug);
            } else {
                logger_->set_level(spdlog::level::info);
            }
            logger_->flush_on(LOG_FLUSH_ON);
        };
        try {
            function();
        } catch (...) {
            throw std::runtime_error("construct logger failed");
        }
    }

    template <typename... Args>
    inline void log_error(const char *fmt, Args... args) {
        logger_->error(fmt, args...);
    }

    template <typename... Args>
    inline void log_warn(const char *fmt, Args... args) {
        logger_->warn(fmt, args...);
    }

    template <typename... Args>
    inline void log_info(const char *fmt, Args... args) {
        logger_->info(fmt, args...);
    }

    template <typename... Args>
    inline void log_debug(const char *fmt, Args... args) {
        logger_->debug(fmt, args...);
    }

    template <typename... Args>
    inline void log_critical(const char *fmt, Args... args) {
        logger_->critical(fmt, args...);
    }
};

#endif // __LOGGER_H__