/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"

// update only one char
str_t * str_update(str_t * str, va_list ap)
{
    size_t index = va_arg(ap, size_t);
    char * data = va_arg(ap, char *);

    if (index >= str->len) {
        index = str->len - 1;
    }

    str->data[index] = * data;

    return str;
}
