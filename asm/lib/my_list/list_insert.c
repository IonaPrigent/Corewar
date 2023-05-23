/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"
#include "my_utils.h"

list_t * list_resize(list_t ** ptr, size_t len);

list_t * list_insert(list_t ** ptr, va_list ap)
{
    list_t * list = * ptr;
    size_t index = va_arg(ap, size_t);
    void * data = va_arg(ap, void *);

    if (list->len == list->cap) {
        list = list_resize(ptr, list->cap + 1);
    }

    if (index < list->len) {
        for (size_t n = list->len; n > index; n--) {
            list->data[n] = list->data[n - 1];
        }
    } else if (index > list->len) {
        index = list->len;
    }

    list->data[index] = data;
    list->len += 1;

    return list;
}
