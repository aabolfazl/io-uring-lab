cmake_minimum_required(VERSION 3.10)
project(io_uring_lab C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${URING_INCLUDE_DIRS}
)

add_executable(io_uring_lab src/main.c include/logger.h shared/logger.c)

target_link_libraries(io_uring_lab ${URING_LIBRARIES})

link_directories(${URING_LIBRARY_DIRS})
target_compile_options(io_uring_lab PRIVATE ${URING_CFLAGS})