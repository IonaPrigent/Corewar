/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"
#include "my_utils.h"

str_t * str_resize(str_t ** ptr, size_t new_cap);

str_t * str_insert(str_t ** ptr, va_list ap)
{
    str_t * str = * ptr;
    size_t index = va_arg(ap, size_t);
    char * data = va_arg(ap, char *);
    size_t len_data = str_len(data);

    if (str->len + len_data + 1 > str->cap) {
        str = str_resize(ptr, str->len + len_data + 1);
    }
    if (index < str->len) {
        for (size_t n = str->len - 1 + len_data; n > index; n--) {
            str->data[n] = str->data[n - len_data];
        }
    } else if (index > str->len) {
        index = str->len;
    }
    mem_cpy(str->data + index, data, len_data);
    str->len += len_data;
    str->data[str->len] = '\0';

    return str;
}
