/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"

str_t * list_to_string(list_t * list, str_t ** buff)
{
    str_t * str = NULL;

    if (buff == NULL) {
        str = create(STR, "[\n");
    } else {
        str = * buff;
        append(&str, "[\n");
    }
    for (size_t i = 0; i < list->len; i++) {
        string(list->data[i], &str);
        append(&str, "\n");
    }
    append(&str, "]");
    if (buff != NULL) {
        * buff = str;
    }
    return str;
}
