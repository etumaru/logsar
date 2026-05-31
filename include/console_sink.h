//
// Created by Elijah Wandimi on 13/02/2026.
//

#pragma once
#include "sink.h"
#include <iostream>

namespace logsar {

    class ConsoleSink final : public Sink {
    public:
        void log(const LogMessage& message) override {
            std::cout << "["
                      << toString(message.level)
                      << "] "
                      << message.message
                      << std::endl;
        }
    };

}

