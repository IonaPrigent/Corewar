/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"

dict_t * dict_duplic(dict_t * dict)
{
    dict_t * new = create(DICT, dict->cap);

    for (size_t i = 0; i < dict->cap; i++) {
        if (dict->buck[i] == NULL) {
            continue;
        }
        new->buck[i] = duplic(dict->buck[i]);
    }

    return new;
}
