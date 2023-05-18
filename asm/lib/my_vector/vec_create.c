/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"
#include "my_utils.h"

void * vec_create(va_list ap)
{
    int size_data = va_arg(ap, int);
    size_t len = va_arg(ap, size_t);
    size_t cap = pad_len(len);
    vec_t * vec = alloc_obj(VEC, sizeof(vec_t) + cap * size_data);

    vec->size_data = size_data;
    vec->cap = cap;
    vec->len = 0;

    return vec;
}
