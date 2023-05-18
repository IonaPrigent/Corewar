/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"
#include "my_utils.h"

list_t * list_create(va_list ap)
{
    size_t len = va_arg(ap, size_t);
    size_t cap = pad_len(len);
    list_t * list = alloc_obj(LIST, sizeof(list_t) + cap * sizeof(void *));

    list->len = 0;
    list->cap = cap;

    return list;
}
