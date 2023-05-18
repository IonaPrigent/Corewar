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
    append(str, TOSTR(va_arg(ap, int)));
}

void add_str(str_t ** str, va_list ap)
{
    append(str, va_arg(ap, char *));
}

void add_int(str_t ** str, va_list ap)
{
    AUTOFREE str_t * tmp = STR(my_itoa(va_arg(ap, int)));

    append(str, tmp->data);
}

void add_flt(str_t ** str, va_list ap)
{
    AUTOFREE str_t * tmp = STR(my_ftoa(va_arg(ap, double), 6));

    append(str, tmp->data);
}

void add_obj(str_t ** str, va_list ap)
{
    string(va_arg(ap, void *), str);
}
