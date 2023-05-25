/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** convert
*/

#include <stdio.h>
#include "corewar_type.h"

void reverse(void *nbr, size_t size)
{
    octet_t octet;
    octet_t *nb = nbr;

    for (size_t i = 0; i < size / 2; ++i) {
        octet = nb[i];
        nb[i] = nb[size - 1 - i];
        nb[size - 1 - i] = octet;
    }
}

void copy(void *dest, void *src, size_t size)
{
    octet_t *dest_oct = dest;
    octet_t *src_oct = src;

    for (size_t i = 0; i < size; ++i) {
        dest_oct[i] = src_oct[i];
    }
}
