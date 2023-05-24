/*
** EPITECH PROJECT, 2023
** mem_cpy.c
** File description:
** utils
*/

#include "my_utils.h"

long int my_atoi(const char * str)
{
    long int nbr = 0;

    while (*str) {
        nbr = nbr * 10 + (*str - '0');
        str++;
    }

    return nbr;
}
