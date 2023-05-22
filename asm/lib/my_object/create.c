/*
** EPITECH PROJECT, 2023
** create_obj.c
** File description:
** create an object
*/

#include "my_object.h"

str_t * str_create(va_list ap);
str_t * str_ncreate(va_list ap);
void * vec_create(va_list ap);
list_t * list_create(va_list ap);
dict_t * dict_create(va_list ap);

// this should be a double array for NSTR
static const void * CREATE[4][2] = {
    {&str_create, &str_ncreate},
    {&vec_create},
    {&list_create},
    {&dict_create},
};

void * create(float type, ...)
{
    void * obj = NULL;
    int obj_type = (int) type;
    int create_way = (type - obj_type) * 10;
    void * (* create_obj)(va_list) = CREATE[obj_type][create_way];
    va_list ap;

    va_start(ap, type);
    obj = create_obj(ap);
    va_end(ap);

    return obj;
}
