/*
** EPITECH PROJECT, 2023
** mem_cpy.c
** File description:
** utils
*/

#include "my_utils.h"

int str_cmp(const char * s1, const char * s2)
{
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}
