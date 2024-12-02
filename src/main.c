#include <stdio.h>
#include <linux/version.h>
#include "logger.h"

int main() {
#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 1, 0)
    LOGI("Supports basic features");
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 6, 0)
    LOGI("Supports advanced networking features");
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 19, 0)
    LOGI("Supports multishot accept");
#endif

    LOGI("Hello, io_uring lab! This project is going to the moon 🚀");

    return 0;
}