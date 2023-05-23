/*
** EPITECH PROJECT, 2023
** mem_cpy.c
** File description:
** utils
*/

#include "my_print.h"
#include "my_utils.h"

void add_chr(str_t ** str, va_list ap)
{
    append(str, TOSTR((char) va_arg(ap, int)));
}

void add_str(str_t ** str, va_list ap)
{
    append(str, va_arg(ap, char *));
}

void add_int(str_t ** str, va_list ap)
{
    char * nbr = my_itoa(va_arg(ap, int));
    AUTOFREE str_t * tmp = STR(nbr);

    append(str, tmp->data);
    free(nbr);
}

void add_flt(str_t ** str, va_list ap)
{
    char * nbr = my_ftoa(va_arg(ap, double), 6);
    AUTOFREE str_t * tmp = STR(nbr);

    append(str, tmp->data);
    free(nbr);
}

void add_obj(str_t ** str, va_list ap)
{
    string(va_arg(ap, void *), str);
}
