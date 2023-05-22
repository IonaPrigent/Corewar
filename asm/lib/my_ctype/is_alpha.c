/*
** EPITECH PROJECT, 2023
** mem_cpy.c
** File description:
** utils
*/

#include "my_ctype.h"

int is_alpha(char c)
{
    return (is_lower(c) || is_upper(c));
}
