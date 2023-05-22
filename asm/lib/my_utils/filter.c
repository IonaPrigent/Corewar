/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_utils.h"

list_str_t * filter(list_str_t * list)
{
    size_t i = 0;

    while (i < list->len) {
        if (list->data[i]->len == 0) {
            delete(list, i);
        } else {
            i++;
        }
    }

    return list;
}
