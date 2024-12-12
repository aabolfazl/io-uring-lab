add_executable(socket_close 
    socket_close.c
    socket_close.h
)

target_link_libraries(socket_close
    PRIVATE shared_lib
)