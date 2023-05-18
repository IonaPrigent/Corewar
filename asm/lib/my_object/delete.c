/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"

str_t * str_delete(str_t * str, va_list ap);
void * vec_delete(vec_t * vec, va_list ap);
list_t * list_delete(list_t * list, va_list ap);
dict_t * dict_delete(dict_t * dict, va_list ap);

static const void * DELETE_DATA[] = {
    &str_delete,
    &vec_delete,
    &list_delete,
    &dict_delete,
};

void * delete(void * obj, ...)
{
    int type = get_obj_type(obj);
    void * (* delete_data)(void *, va_list) = DELETE_DATA[type];
    va_list ap;

    va_start(ap, obj);
    obj = delete_data(obj, ap);
    va_end(ap);

    return obj;
}
