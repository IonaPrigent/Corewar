/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"

void * vec_insert(void ** ptr, va_list ap);

static void * convert_to_insert(void ** ptr, ...)
{
    vec_t * vec = NULL;
    va_list ap;

    va_start(ap, ptr);
    vec = vec_insert(ptr, ap);
    va_end(ap);

    return vec;
}

void * vec_append(void ** ptr, va_list ap)
{
    vec_t * vec = * ptr;
    size_t index = vec->len;
    void * data = va_arg(ap, void *);

    return convert_to_insert(ptr, index, data);
}
