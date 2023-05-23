/*
** EPITECH PROJECT, 2023
** mem_cpy.c
** File description:
** utils
*/

#include "my_utils.h"

char * str_cpy(char * dst, const char * src)
{
    size_t i = 0;

    for (; src[i] != '\0'; i++) {
        dst[i] = src[i];
    }
    dst[i] = '\0';

    return dst;
}
