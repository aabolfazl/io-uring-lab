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

#ifndef ARG_PARSER_H
#define ARG_PARSER_H

#include <stdio.h>

typedef enum { TYPE_STRING, TYPE_INT, TYPE_LONG, TYPE_FLOAT } option_type_s;

typedef struct {
    const char* flag;
    const char* description;
    option_type_s type;
    const char* default_value;
    union {
        char* string_value;
        int int_value;
        long long_value;
        float float_value;
    } value;
} option_t;

int parse_arguments(int argc, char* argv[], option_t* options, int option_count);

#endif // ARG_PARSER_H