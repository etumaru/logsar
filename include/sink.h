//
// Created by Elijah Wandimi on 13/02/2026.
//

#pragma once

#ifndef SINK_H
#define SINK_H

#include "message.h"

namespace logsar {
    class Sink {
        public:
        virtual ~Sink() = default;
        virtual void log(const LogMessage& message) = 0;
    };
}

#endif //SINK_H
