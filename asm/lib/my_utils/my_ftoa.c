/*
** EPITECH PROJECT, 2023
** mem_cpy.c
** File description:
** utils
*/

#include <stdlib.h>

#include "my_utils.h"
#include "my_def.h"

char * my_ftoa(double nbr, int precision)
{
    char * int_ = my_itoa(nbr);
    char * flt_ = NULL;
    char * s = NULL;
    int neg_zero = (nbr < 0 && nbr > -1);

    if (precision <= 0)
        return int_;

    nbr -= (long int) nbr;
    nbr *= power(10, (precision < 0) ? 0 : precision);
    flt_ = my_itoa(ABS(nbr));
    s = malloc(sizeof(char) * (str_len(int_) + str_len(flt_) + 2 + neg_zero));
    if (neg_zero)
        s[0] = '-';
    str_cpy(s + neg_zero, int_);
    str_cat(s, ".");
    str_cat(s, flt_);

    vfree(2, int_, flt_);
    return s;
}
