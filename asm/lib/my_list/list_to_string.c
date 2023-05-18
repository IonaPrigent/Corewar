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
        str = create(STR, "[");
    } else {
        str = * buff;
        append(&str, "[");
    }
    for (size_t i = 0; i < list->len; i++) {
        string(list->data[i], &str);
        append(&str, ", ");
    }
    if (str->data[str->len - 1] == ' ') {
        str->len -= 2;
    }
    append(&str, "]");
    if (buff != NULL) {
        * buff = str;
    }
    return str;
}
