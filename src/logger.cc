#include "logger.h"

#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>

namespace logsar {
    class LoggerImpl {
        std::ofstream file_;

        std::string timeToString(const std::chrono::system_clock::time_point tp) {
            const std::time_t time = std::chrono::system_clock::to_time_t(tp);
            const std::tm tm = *std::localtime(&time);

            std::ostringstream oss;
            oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
            return oss.str();
        }

        void log(const LogMessage& message) {
            if (!file_.is_open()) return;

            file_ << "{"
              << R"("level":")" << toString(message.level) << "\","
              << R"("timestamp":")" << timeToString(message.timestamp) << "\","
              << R"("message":")" << message.message << "\""
              << "}"
              << std::endl;
        }

        public:
        LoggerImpl(): file_("logs.json", std::ios::app) {}

        void info(std::string_view message) {
            LogMessage logMessage{
                LogLevel::INFO,
                std::chrono::system_clock::now(),
                message
            };

            log(logMessage);
        }

        void debug(std::string_view message) {
            LogMessage logMessage{
                LogLevel::DEBUG,
                std::chrono::system_clock::now(),
                message
            };

            log(logMessage);
        }

        void error(std::string_view message) {
            LogMessage logMessage{
                LogLevel::ERROR,
                std::chrono::system_clock::now(),
                message
            };

            log(logMessage);
        }

        void warn(std::string_view message) {
            LogMessage logMessage{
                LogLevel::WARN,
                std::chrono::system_clock::now(),
                message
            };

            log(logMessage);
        }

    };

    Logger::Logger() : impl_(std::make_unique<LoggerImpl>()) {}
    Logger::~Logger() = default;
    Logger &Logger::operator=(Logger&&) noexcept = default;


    void Logger::info(const std::string_view message) const {
        impl_ ->info(message);
    }

    void Logger::debug(const std::string_view message) const {
        impl_ ->debug(message);
    }

    void Logger::error(const std::string_view message) const{
        impl_ ->error(message);
    }

    void Logger::warn(const std::string_view message) const {
        impl_ ->warn(message);
    }
}
