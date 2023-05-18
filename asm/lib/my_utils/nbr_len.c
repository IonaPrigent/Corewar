/*
** EPITECH PROJECT, 2023
** mem_cpy.c
** File description:
** utils
*/

#include "my_utils.h"

size_t nbr_len(long int nbr)
{
    size_t len = 0;
    int sign = nbr < 0;

    if (nbr == 0)
        return 1;

    while (nbr != 0) {
        nbr /= 10;
        len += 1;
    }

    return len + sign;
}
