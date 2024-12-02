#include "logger.h"

static char *get_timestamp() {
    static char timestamp[64];
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm_info);
    return timestamp;
}

void log_message(LogLevel level, const char *format, ...) {
    const char *level_str = (level == LOG_LEVEL_ERROR) ? "E" : "I";
    FILE *output = (level == LOG_LEVEL_ERROR) ? stderr : stdout;

    fprintf(output, "%s | %s | %d | ", get_timestamp(), level_str, getpid());

    va_list args;
    va_start(args, format);
    vfprintf(output, format, args);
    va_end(args);

    fprintf(output, "\n");
}
