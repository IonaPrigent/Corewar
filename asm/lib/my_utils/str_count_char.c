/*
** EPITECH PROJECT, 2023
** pad_len.c
** File description:
** utils
*/

#include "my_utils.h"

size_t str_count_char(const char * str, char c)
{
    size_t count = 0;

    while (*str) {
        if (*str == c) {
            count++;
        }
        str++;
    }

    return count;
}
