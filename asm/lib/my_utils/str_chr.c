/*
** EPITECH PROJECT, 2023
** mem_cpy.c
** File description:
** utils
*/

#include "my_utils.h"

char * str_chr(const char * str, char chr)
{
    while (*str) {
        if (*str == chr) {
            return (char *) str;
        }
        str++;
    }

    return NULL;
}
