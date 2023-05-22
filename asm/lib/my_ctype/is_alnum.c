/*
** EPITECH PROJECT, 2023
** mem_cpy.c
** File description:
** utils
*/

#include "my_ctype.h"

int is_alnum(char c)
{
    return (is_alpha(c) || is_digit(c));
}
