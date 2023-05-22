/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"

void set_obj_type(void * obj, int type)
{
    ((int *) obj)[-1] = type;
}

int get_obj_type(void * obj)
{
    return ((int *) obj)[-1];
}
