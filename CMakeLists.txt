cmake_minimum_required(VERSION 3.10)
project(io_uring_lab C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/shared
    ${URING_INCLUDE_DIRS}
)

set(SHARED_SOURCES
    shared/logger.c
    shared/argument_parser.c
)

add_executable(io_uring_lab
    src/main.c
    ${SHARED_SOURCES}
)

target_link_libraries(io_uring_lab ${URING_LIBRARIES})

target_compile_options(io_uring_lab PRIVATE ${URING_CFLAGS})
