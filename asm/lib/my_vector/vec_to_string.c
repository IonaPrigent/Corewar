/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"
#include "my_utils.h"

// TODO: complex, should transform every element according to its data type
// for now, it does not work
str_t * vec_to_string(vec_t * vec, str_t ** buff)
{
    str_t * str = NULL;
    char * nbr = NULL;

    if (buff == NULL) {
        str = create(STR, "[");
    } else {
        str = * buff;
        append(&str, "[");
    }
    for (size_t i = 0; i < vec->len; i++) {
        nbr = my_itoa(((long *) vec->data)[i]);
        append(&str, nbr);
        append(&str, ", ");
        free(nbr);
    }

    if (str->data[str->len - 1] == ' ') {
        delete(str, str->len);
        delete(str, str->len);
    }
    append(&str, "]");

    if (buff != NULL) {
        *buff = str;
    }

    return str;
}
