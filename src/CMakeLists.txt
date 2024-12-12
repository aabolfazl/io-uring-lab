add_executable(io_uring_lab main.c)

target_link_libraries(io_uring_lab
    PRIVATE shared_lib
    PRIVATE ${URING_LIBRARIES}
)

target_compile_options(io_uring_lab 
    PRIVATE ${URING_CFLAGS}
)