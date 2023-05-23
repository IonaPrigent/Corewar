/*
** EPITECH PROJECT, 2023
** create_obj.c
** File description:
** create an object
*/

#include "my_object.h"

str_t * str_duplic(str_t * vec);
void * vec_duplic(vec_t * vec);
list_t * list_duplic(list_t * list);
dict_t * dict_duplic(dict_t * dict);

static const void * DUPLICATE[] = {
    &str_duplic,
    &vec_duplic,
    &list_duplic,
    &dict_duplic,
};

void * duplic(void * obj)
{
    int type = get_obj_type(obj);
    void * (* duplicate)(void * obj) = DUPLICATE[type];
    void * new = duplicate(obj);

    return new;
}
