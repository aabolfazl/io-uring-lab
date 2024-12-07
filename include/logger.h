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

#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <unistd.h>

typedef enum {
    LOG_LEVEL_ERROR,
    LOG_LEVEL_INFO
} LogLevel;

void log_message(LogLevel level, const char *format, ...);

#define LOGE(format, ...) log_message(LOG_LEVEL_ERROR, format, ##__VA_ARGS__)
#define LOGI(format, ...) log_message(LOG_LEVEL_INFO, format, ##__VA_ARGS__)

#endif // LOGGER_H
