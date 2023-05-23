/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"
#include "my_utils.h"

list_t * list_delete(list_t * list, va_list ap)
{
    size_t index = va_arg(ap, size_t);

    if (index >= list->len) {
        index = list->len - 1;
    }

    destroy(list->data[index]);

    if (index < list->len - 1) {
        mem_cpy(
            list->data + index,
            list->data + index + 1,
            (list->len - index - 1) * sizeof(void *)
        );
    }
    list->len -= 1;

    return list;
}
