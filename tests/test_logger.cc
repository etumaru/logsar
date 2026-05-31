//
// Created by Elijah Wandimi on 11/08/2025.
//

#include "logger.h"
#include <iostream>

int main() {
    const logsar::Logger logger;
    logger.info("Nice try, now the work begins!");
    logger.error("Backoff, now's not the time!!");
    logger.debug("Something is happening, no idea what!");

    std::cout << "[TEST] If you see the log above, it works.\n";
    return 0;
}
