/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"

// TODO: delete header to see if it works

void set_obj_type(void * obj, int type)
{
    ((int *) obj)[-1] = type;
}

int get_obj_type(void * obj)
{
    return ((int *) obj)[-1];
}
