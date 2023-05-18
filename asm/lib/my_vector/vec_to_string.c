/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"

// TODO: complex, should transform every element according to its data type
// for now, it does not work
str_t * vec_to_string(vec_t * vec, str_t ** buff)
{
    str_t * str = NULL;

    if (buff == NULL) {
        str = create(STR, "\"");
    } else {
        str = * buff;
        append(&str, "\"");
    }

    append(&str, vec->data);
    append(&str, "\"");

    if (buff != NULL) {
        * buff = str;
    }

    return str;
}
