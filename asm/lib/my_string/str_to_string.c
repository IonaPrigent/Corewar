/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"

str_t * str_to_string(str_t * src, str_t ** buff)
{
    str_t * str = NULL;

    if (buff == NULL) {
        str = create(STR, "\"");
    } else {
        str = *buff;
        append(&str, "\"");
    }

    append(&str, src->data);
    append(&str, "\"");

    if (buff != NULL) {
        *buff = str;
    }

    return str;
}
