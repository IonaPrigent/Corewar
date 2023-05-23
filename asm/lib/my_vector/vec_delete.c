/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"
#include "my_utils.h"

void * vec_delete(vec_t * vec, va_list ap)
{
    size_t index = va_arg(ap, size_t);

    if (index < vec->len - 1) {
        mem_cpy(
            vec->data + index * vec->size_data,
            vec->data + (index + 1) * vec->size_data,
            (vec->len - index - 1) * vec->size_data
        );
    }
    vec->len -= 1;

    return vec;
}
