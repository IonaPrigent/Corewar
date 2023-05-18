/*
** EPITECH PROJECT, 2023
** create_obj.c
** File description:
** create an object
*/

#include "my_object.h"

str_t * str_update(str_t * str, va_list ap);
void * vec_update(vec_t * vec, va_list ap);
list_t * list_update(list_t * ptr, va_list ap);
dict_t * dict_update(dict_t * ptr, va_list ap);

static const void * UPDATE[] = {
    &str_update,
    &vec_update,
    &list_update,
    &dict_update,
};

void * update(void * obj, ...)
{
    int type = get_obj_type(obj);
    void * (* update_data)(void *, va_list) = UPDATE[type];
    va_list ap;

    va_start(ap, obj);
    obj = update_data(obj, ap);
    va_end(ap);

    return obj;
}
