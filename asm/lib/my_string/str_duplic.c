/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"
#include "my_utils.h"

str_t * str_duplic(str_t * str)
{
    str_t * new = alloc_obj(STR, sizeof(str_t) + str->cap * sizeof(char));

    new->cap = str->cap;
    new->len = str->len;
    mem_cpy(new->data, str->data, str->len);
    new->data[new->len] = '\0';

    return new;
}
