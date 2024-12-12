cmake_minimum_required(VERSION 3.10)
project(io_uring_lab C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_library(shared_lib STATIC
    shared/logger.c
    shared/argument_parser.c
)

target_include_directories(shared_lib PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/shared
)

add_subdirectory(src)

add_subdirectory(src/net/connection_event)
