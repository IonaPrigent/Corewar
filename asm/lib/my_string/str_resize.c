/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"
#include "my_utils.h"

// TODO: create the resize function
str_t * str_resize(str_t ** ptr, size_t new_cap)
{
    str_t * old = * ptr;
    str_t * new = alloc_obj(STR, sizeof(str_t) + new_cap * sizeof(char));

    new->cap = new_cap;
    new->len = old->len;
    mem_cpy(new->data, old->data, old->len);
    new->data[new->len] = '\0';

    destroy(old);
    * ptr = new;
    return new;
}
