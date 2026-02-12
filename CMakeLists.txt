cmake_minimum_required(VERSION 3.31)
project(logsar VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)

# -------------------------------------------------------------
# logsar C++ Library
# -------------------------------------------------------------
add_library(logsar SHARED
        src/logger.cc
        src/utils/sink.cc
)

target_include_directories(logsar PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# -------------------------------------------------------------
# C API Library Wrapper
# -------------------------------------------------------------
#add_library(logsarc SHARED
#        c_api/logger_capi.cpp
#        c_api/logger_c.h
#)
#
#target_link_libraries(logsarc PUBLIC logsar)
#
#target_include_directories(logsarc PUBLIC
#        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/c_api>
#)
#
#set_target_properties(logsarc PROPERTIES
#        VERSION ${PROJECT_VERSION}
#        SOVERSION 1
#)

# -------------------------------------------------------------
# Example executable
# -------------------------------------------------------------
#add_executable(example examples/basic_usage.cpp)
#target_link_libraries(example logsarc)

# -------------------------------------------------------------
# Tests
# -------------------------------------------------------------
add_executable(tests
        tests/test_logger.cc
)

target_link_libraries(tests PRIVATE logsar)
