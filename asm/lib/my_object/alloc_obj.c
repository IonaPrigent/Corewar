/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"

void * alloc_obj(int type, size_t size)
{
    void * obj = malloc(sizeof(int) + size) + sizeof(int);

    set_obj_type(obj, type);

    return obj;
}
