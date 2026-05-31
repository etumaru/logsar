//
// Created by Elijah Wandimi on 13/02/2026.
//

#pragma once
#include "sink.h"
#include <fstream>
#include <iomanip>
#include <sstream>

namespace logsar {

    class FileSink final : public Sink {
        std::ofstream file_;

        static std::string timeToString(const std::chrono::system_clock::time_point tp) {
            const std::time_t time = std::chrono::system_clock::to_time_t(tp);
            const std::tm tm = *std::localtime(&time);

            std::ostringstream oss;
            oss << std::put_time(&tm, "%Y-%m-%dT%H:%M:%S");
            return oss.str();
        }

    public:
        explicit FileSink(const std::string& filename)
            : file_(filename, std::ios::app) {}

        void log(const LogMessage& message) override {
            if (!file_.is_open()) return;

            file_ << "{"
                  << "\"level\":\"" << toString(message.level) << "\","
                  << "\"timestamp\":\"" << timeToString(message.timestamp) << "\","
                  << "\"message\":\"" << message.message << "\""
                  << "}"
                  << std::endl;
        }
    };

}
