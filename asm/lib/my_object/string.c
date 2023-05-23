/*
** EPITECH PROJECT, 2023
** create_obj.c
** File description:
** create an object
*/

#include "my_object.h"

str_t * str_to_string(str_t * src, str_t ** buff);
str_t * vec_to_string(vec_t * vec, str_t ** buff);
str_t * list_to_string(list_t * list, str_t ** buff);
str_t * dict_to_string(dict_t * dict, str_t ** buff);

static const void * CONVERT_TO_STR[] = {
    &str_to_string,
    &vec_to_string,
    &list_to_string,
    &dict_to_string,
};

str_t * string(void * obj, str_t ** buff)
{
    int type = get_obj_type(obj);
    str_t * (* convert_to_str)(void *, str_t **) = CONVERT_TO_STR[type];
    str_t * str = convert_to_str(obj, buff);

    return str;
}
