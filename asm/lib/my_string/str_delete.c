/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"
#include "my_utils.h"

str_t * str_delete(str_t * str, va_list ap)
{
    size_t index = va_arg(ap, size_t);

    if (index < str->len - 1) {
        mem_cpy(
            str->data + index,
            str->data + index + 1,
            str->len - index - 1
        );
    }
    str->len -= 1;
    str->data[str->len] = '\0';

    return str;
}
