/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"

str_t * str_insert(str_t ** ptr, va_list ap);

static str_t * convert_to_insert(str_t ** ptr, ...)
{
    str_t * str = NULL;
    va_list ap;

    va_start(ap, ptr);
    str = str_insert(ptr, ap);
    va_end(ap);

    return str;
}

str_t * str_append(str_t ** ptr, va_list ap)
{
    size_t index = (* ptr)->len;
    char * data = va_arg(ap, char *);

    return convert_to_insert(ptr, index, data);
}
