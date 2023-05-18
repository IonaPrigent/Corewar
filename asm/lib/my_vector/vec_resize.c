/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"
#include "my_utils.h"

void vec_destroy(vec_t * vec);

void * vec_resize(void ** ptr, size_t new_cap)
{
    vec_t * old = * ptr;
    vec_t * new = create(VEC, old->size_data, new_cap);

    new->len = old->len;
    mem_cpy(new->data, old->data, old->len * old->size_data);

    vec_destroy(old);
    * ptr = new;
    return new;
}
