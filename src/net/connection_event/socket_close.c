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

#include <stdio.h>

#include "argument_parser.h"
#include "logger.h"
#include "socket_utils.h"

int main(int argc, char* argv[]) {

    option_t options[] = {{"-i", "remote ip", TYPE_STRING, NULL, {.string_value = NULL}},
                          {"-p", "remote port", TYPE_INT, "8080", {.int_value = 0}}};

    int option_count = sizeof(options) / sizeof(options[0]);
    if (parse_arguments(argc, argv, options, option_count) != 0) {
        LOGE("Failed to parse arguments.");
        return 1;
    }

    const char* ip = options[0].value.string_value;
    int port = options[1].value.int_value;

    LOGI("Remote IP: %s %d", ip, port);

    int sock_fd = create_tcp_socket();
    if (sock_fd == -1) {
        exit(EXIT_FAILURE);
    }

    

    return 0;
}