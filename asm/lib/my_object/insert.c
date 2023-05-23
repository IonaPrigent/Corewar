/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"

str_t * str_insert(str_t ** ptr, va_list ap);
void * vec_insert(void ** ptr, va_list ap);
list_t * list_insert(list_t ** ptr, va_list ap);
dict_t * dict_insert(dict_t ** ptr, va_list ap);

static const void * INSERT[] = {
    &str_insert,
    &vec_insert,
    &list_insert,
    &dict_insert,
};

void * insert(void * ptr, ...)
{
    void * obj = * (void ** )ptr;
    int type = get_obj_type(obj);
    void * (* insert_data)(void **, va_list) = INSERT[type];
    va_list ap;

    va_start(ap, ptr);
    obj = insert_data(ptr, ap);
    va_end(ap);

    return obj;
}
