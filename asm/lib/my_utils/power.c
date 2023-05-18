/*
** EPITECH PROJECT, 2023
** mem_cpy.c
** File description:
** utils
*/

#include "my_utils.h"

double power(int x, int p)
{
    int isneg = (p < 0);
    double nbr = 1;

    while (p != 0) {
        nbr *= x;
        p += (isneg) ? 1 : -1;
    }

    return (isneg) ? 1.0 / nbr : nbr;
}
