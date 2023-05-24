/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** convert
*/

#include <stdio.h>

void reverse(void *nbr, size_t size)
{
    char octet;
    char *nb = nbr;

    for (size_t i = 0; i < size / 2; ++i) {
        octet = nb[i];
        nb[i] = nb[size - 1 - i];
        nb[size - 1 - i] = octet;
    }
}
