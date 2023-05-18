/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"

str_t * str_append(str_t ** ptr, va_list ap);
void * vec_append(void ** ptr, va_list ap);
list_t * list_append(list_t ** ptr, va_list ap);
dict_t * dict_append(dict_t ** ptr, va_list ap);

static const void * APPEND_DATA[] = {
    &str_append,
    &vec_append,
    &list_append,
    &dict_append,
};

void * append(void * ptr, ...)
{
    void * obj = * (void **) ptr;
    int type = get_obj_type(obj);
    void * (* append_data)(void **, va_list) = APPEND_DATA[type];
    va_list ap;

    va_start(ap, ptr);
    obj = append_data(ptr, ap);
    va_end(ap);

    return obj;
}
