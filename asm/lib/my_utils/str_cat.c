/*
** EPITECH PROJECT, 2023
** mem_cpy.c
** File description:
** utils
*/

#include "my_utils.h"

char * str_cat(char * dst, const char * src)
{
    dst += str_len(dst);

    while (*src) {
        *dst = *src;
        src += 1;
    }
    *dst = '\0';

    return dst;
}
