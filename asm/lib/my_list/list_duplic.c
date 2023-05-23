/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"

list_t * list_duplic(list_t * list)
{
    list_t * new = create(LIST, list->cap);

    for (size_t i = 0; i < list->len; i++) {
        new->data[i] = duplic(list->data[i]);
    }
    new->len = list->len;

    return new;
}
