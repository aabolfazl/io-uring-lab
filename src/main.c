#include <stdio.h>
#include <linux/version.h>

int main() {
    #if LINUX_VERSION_CODE >= KERNEL_VERSION(5,1,0)
        printf("Supports basic features\n");
    #endif

    #if LINUX_VERSION_CODE >= KERNEL_VERSION(5,6,0)
        printf("Supports advanced networking features\n");
    #endif

    #if LINUX_VERSION_CODE >= KERNEL_VERSION(5,19,0)
        printf("Supports multishot accept\n");
    #endif

    return 0;
}