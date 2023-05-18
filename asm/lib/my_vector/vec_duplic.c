/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"
#include "my_utils.h"

void * vec_duplic(vec_t * vec)
{
    vec_t * new = create(VEC, vec->size_data, vec->cap);

    new->len = vec->len;
    mem_cpy(new->data, vec->data, vec->len * vec->size_data);

    return new;
}
