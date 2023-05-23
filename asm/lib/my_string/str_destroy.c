/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"
#include "my_utils.h"

void str_destroy(str_t * str)
{
    try_free((int *) str - 1);
}
