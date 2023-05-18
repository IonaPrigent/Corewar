/*
** EPITECH PROJECT, 2023
** pad_len.c
** File description:
** utils
*/

#include "my_utils.h"

size_t pad_len(size_t nbr)
{
    size_t cap = 1;

    while (cap < nbr) {
        cap *= 2;
    }

    return cap;
}
