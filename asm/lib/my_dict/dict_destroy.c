/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"

void dict_destroy(dict_t * dict)
{
    if (dict == NULL) {
        return;
    }

    for (size_t i = 0; i < dict->cap; i++) {
        destroy(dict->buck[i]);
    }

    free((int *) dict - 1);
}
