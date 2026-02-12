#pragma once
#include <memory>
#include "message.h"
#include "level.h"
#include "string_view"
#include "iostream"
#include <chrono>

namespace logsar {
    class LoggerImpl;
    class Sink;

    /**
     * @brief The main logging class.
     *
     * This class provides a public interface for logging messages at different severity levels.
     * It uses the Pimpl (Pointer to implementation) design pattern to hide internal details.
     */
    class Logger {
    public:
        Logger();
        ~Logger();
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;
        Logger(Logger&&) = delete;
        Logger& operator=(Logger&&) noexcept;
        void writeLog(LogLevel level, std::string_view message);
        void info(std::string_view message) const;
        void debug(std::string_view message) const;
        void error(std::string_view message) const;
        void warn(std::string_view message) const;

    private:
        std::unique_ptr<LoggerImpl> impl_;
		void log(const LogMessage& message);
    };
}