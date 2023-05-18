/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"
#include "my_utils.h"

static str_t * string_create(char * data, size_t len)
{
    size_t cap = pad_len(len + 1);
    str_t * str = alloc_obj(STR, sizeof(str_t) + cap * sizeof(char));

    str->cap = cap;
    str->len = len;
    mem_cpy(str->data, data, len);
    str->data[len] = '\0';

    return str;
}

str_t * str_create(va_list ap)
{
    char * data = va_arg(ap, char *);
    size_t len = str_len(data);

    return string_create(data, len);
}

str_t * str_ncreate(va_list ap)
{
    size_t len = va_arg(ap, size_t);
    char * data = va_arg(ap, char *);

    return string_create(data, len);
}
