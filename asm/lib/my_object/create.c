/*
** EPITECH PROJECT, 2023
** create_obj.c
** File description:
** create an object
*/

#include "my_object.h"

str_t * str_create(va_list ap);
void * vec_create(va_list ap);
list_t * list_create(va_list ap);
dict_t * dict_create(va_list ap);
// void * create_nstr(va_list ap);

// this should be a double array for NSTR
static const void * CREATE[] = {
    &str_create,
    &vec_create,
    &list_create,
    &dict_create,
};

void * create(int type, ...)
{
    void * obj = NULL;
    void * (* create_obj)(va_list) = CREATE[type];
    va_list ap;

    va_start(ap, type);
    obj = create_obj(ap);
    va_end(ap);

    return obj;
}
