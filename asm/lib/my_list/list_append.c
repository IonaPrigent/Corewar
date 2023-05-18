/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"
#include "my_utils.h"

list_t * list_insert(list_t ** ptr, va_list ap);

static list_t * convert_to_insert(list_t ** ptr, ...)
{
    list_t * list = NULL;
    va_list ap;

    va_start(ap, ptr);
    list = list_insert(ptr, ap);
    va_end(ap);

    return list;
}

list_t * list_append(list_t ** ptr, va_list ap)
{
    size_t index = (* ptr)->len;
    void * data = va_arg(ap, void *);

    return convert_to_insert(ptr, index, data);
}
