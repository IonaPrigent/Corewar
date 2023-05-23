/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"

static void add_bucket(list_t * bucket, str_t ** str)
{
    for (size_t n = 0; n < bucket->len; n += 2) {
        string(bucket->data[n], str);
        append(str, ": ");
        string(bucket->data[n + 1], str);
        append(str, ", ");
    }
}

str_t * dict_to_string(dict_t * dict, str_t ** buff)
{
    str_t * str = NULL;

    if (buff == NULL) {
        str = create(STR, "{");
    } else {
        str = *buff;
        append(&str, "{");
    }
    for (size_t i = 0; i < dict->cap; i++) {
        if (dict->buck[i] == NULL)
            continue;
        add_bucket(dict->buck[i], &str);
    }
    if (str->data[str->len - 1] == ' ')
        str->len -= 2;
    append(&str, "}");

    if (buff != NULL)
        *buff = str;
    return str;
}
