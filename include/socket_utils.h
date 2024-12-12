/*
 * Copyright © 2024 Io-Uring-Lab project
 *
 * This is the source code of the Io-Uring-Lab project.
 * It is licensed under the MIT License; you should have received a copy
 * of the license in this archive (see LICENSE).
 *
 * Author: Abolfazl Abbasi
 *
 */

#ifndef IO_URING_LAB_SOCKET_UTILS_H
#define IO_URING_LAB_SOCKET_UTILS_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/syscall.h>
#include <sys/socket.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include "logger.h"


static inline int create_tcp_socket() {
    int sock_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
    if (sock_fd < 0) {
        LOGE("Failed to create socket: %s", strerror(errno));
        return -1;
    }
    return sock_fd;
}

static inline int set_socket_options(int sock_fd) {
    int opt = 1;
    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        LOGE("Failed to set SO_REUSEADDR: %s", strerror(errno));
        return -1;
    }

    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        LOGE("Failed to set SO_REUSEPORT: %s", strerror(errno));
        return -1;
    }
    
    return 0;
}

static inline int bind_socket(int sock_fd, uint16_t port, const char* address) {
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    if (inet_pton(AF_INET, address, &addr.sin_addr) <= 0) {
        LOGE("Invalid address: %s", address);
        return -1;
    }

    if (bind(sock_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        LOGE("Failed to bind socket: %s", strerror(errno));
        return -1;
    }

    return 0;
}

static inline int start_listening(int sock_fd, int backlog) {
    if (listen(sock_fd, backlog) < 0) {
        LOGE("Failed to listen: %s", strerror(errno));
        return -1;
    }
    return 0;
}

static inline void close_socket(int sock_fd) {
    if (sock_fd >= 0) {
        close(sock_fd);
    }
}

#endif