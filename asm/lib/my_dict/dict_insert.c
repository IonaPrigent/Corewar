/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"

dict_t * dict_append(dict_t ** ptr, va_list ap);

static dict_t * convert_to_append(dict_t ** ptr, ...)
{
    dict_t * dict = NULL;
    va_list ap;

    va_start(ap, ptr);
    dict = dict_append(ptr, ap);
    va_end(ap);

    return dict;
}

dict_t * dict_insert(dict_t ** ptr, va_list ap)
{
    char * key = va_arg(ap, char *);
    void * data = va_arg(ap, void *);

    return convert_to_append(ptr, key, data);
}
