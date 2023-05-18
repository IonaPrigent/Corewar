/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"
#include "my_utils.h"

list_t * list_resize(list_t ** ptr, size_t len)
{
    list_t * old = * ptr;
    list_t * new = create(LIST, len);

    new->len = old->len;
    mem_cpy(new->data, old->data, old->len * sizeof(void *));

    free((int *) old - 1);
    * ptr = new;
    return new;
}
