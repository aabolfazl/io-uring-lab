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

#include "argument_parser.h"
#include "logger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse_arguments(int argc, char *argv[], option_t *options,
					int option_count) {
	LOGI("Parsing arguments... count: %d opt count %d", argc, option_count);

	for (int i = 0; i < option_count; i++) {
		if (options[i].default_value) {
			switch (options[i].type) {
				case TYPE_STRING:
					options[i].value.string_value =
						strdup(options[i].default_value);
					break;
				case TYPE_INT:
					options[i].value.int_value = atoi(options[i].default_value);
					break;
				case TYPE_LONG:
					options[i].value.long_value =
						atol(options[i].default_value);
					break;
				case TYPE_FLOAT:
					options[i].value.float_value =
						atof(options[i].default_value);
					break;
			}
		}
	}

	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-h") == 0) {
			return 1;
		}

		int found = 0;
		for (int j = 0; j < option_count; j++) {
			if (strcmp(argv[i], options[j].flag) == 0) {
				found = 1;
				if (i + 1 < argc) {
					i++;
					switch (options[j].type) {
						case TYPE_STRING:
							options[j].value.string_value = strdup(argv[i]);
							break;
						case TYPE_INT:
							options[j].value.int_value = atoi(argv[i]);
							break;
						case TYPE_LONG:
							options[j].value.long_value = atol(argv[i]);
							break;
						case TYPE_FLOAT:
							options[j].value.float_value = atof(argv[i]);
							break;
					}
				} else {
					LOGE("Error: Missing value for option '%s'",
						 options[j].flag);
					return -1;
				}
				break;
			}
		}

		if (!found) {
			fprintf(stderr, "Error: Unknown option '%s'\n", argv[i]);
			continue;
		}
	}

	return 0;
}
