/*
** EPITECH PROJECT, 2023
** str_len.c
** File description:
** utils
*/

#include "my_utils.h"

size_t str_len(const char * str)
{
    size_t len = 0;

    while (*str) {
        len += 1;
        str += 1;
    }

    return len;
}
