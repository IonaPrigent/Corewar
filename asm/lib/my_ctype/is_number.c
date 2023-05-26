/*
** EPITECH PROJECT, 2023
** mem_cpy.c
** File description:
** utils
*/

#include <stdlib.h>

#include "my_ctype.h"

int is_number(const char * str, int sign)
{
    if (str == NULL || *str == '\0') {
        return 0;
    }

    if ((sign >= 0 && *str == '+') || (sign <= 0 && *str == '-')) {
        str++;
    }

    while (*str) {
        if (is_digit(*str)) {
            str++;
        } else {
            return 0;
        }
    }

    return 1;
}
