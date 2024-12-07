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

#include <linux/version.h>
#include <stdio.h>

#include "argument_parser.h"
#include "logger.h"

int main(int argc, char *argv[]) {
	LOGI("Linux version: %d.%d.%d", LINUX_VERSION_CODE / 65536,
		 LINUX_VERSION_CODE / 256 % 256, LINUX_VERSION_CODE % 256);

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 1, 0)
	LOGI("Supports basic features");
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 6, 0)
	LOGI("Supports advanced networking features");
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5, 19, 0)
	LOGI("Supports multishot accept");
#endif

	option_t options[] = {
		{"-f", "Specify flags", TYPE_STRING, NULL, {.string_value = NULL}},
		{"-t", "Number of threads", TYPE_INT, "1", {.int_value = 0}},
		{"-m", "Max memory", TYPE_LONG, "1048576", {.long_value = 0}}};
	int option_count = sizeof(options) / sizeof(options[0]);

	if (parse_arguments(argc, argv, options, option_count) != 0) {
		LOGE("Failed to parse arguments.");
		return 1;
	}

	LOGI("Parsed options:");
	for (int i = 0; i < option_count; i++) {
		switch (options[i].type) {
			case TYPE_STRING:
				LOGI("%s: %s", options[i].flag, options[i].value.string_value);
				break;
			case TYPE_INT:
				LOGI("%s: %d", options[i].flag, options[i].value.int_value);
				break;
			case TYPE_LONG:
				LOGI("%s: %ld", options[i].flag, options[i].value.long_value);
				break;
		}
	}

	LOGI("Hello, io_uring lab! This project is going to the moon 🚀");

	return 0;
}