/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"

list_t * list_update(list_t * list, va_list ap)
{
    size_t index = va_arg(ap, size_t);
    void * data = va_arg(ap, void *);

    if (index >= list->len) {
        index = list->len - 1;
    }

    destroy(list->data[index]);
    list->data[index] = data;

    return list;
}
