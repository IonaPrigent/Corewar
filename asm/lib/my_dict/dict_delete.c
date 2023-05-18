/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"

dict_t * dict_delete(dict_t * dict, va_list ap)
{
    char * key = va_arg(ap, char *);
    size_t hash = hash_key(key) % dict->cap;
    size_t index = 0;

    if (key_in_bucket(dict->buck[hash], key, &index)) {
        delete(dict->buck[hash], index);
        delete(dict->buck[hash], index);
    }

    return dict;
}
