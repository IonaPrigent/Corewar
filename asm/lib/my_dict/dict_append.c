/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"

dict_t * dict_append(dict_t ** ptr, va_list ap)
{
    dict_t * dict = * ptr;
    char * key = va_arg(ap, char *);
    void * data = va_arg(ap, void *);
    size_t hash = hash_key(key) % dict->cap;
    size_t index = 0;

    if (dict->buck[hash] == NULL) {
        dict->buck[hash] = create(LIST, 2);
    }

    if (key_in_bucket(dict->buck[hash], key, &index)) {
        destroy(dict->buck[hash]->data[index + 1]);
        dict->buck[hash]->data[index + 1] = data;
    } else {
        append(&(dict->buck[hash]), create(STR, key));
        append(&(dict->buck[hash]), data);
    }

    return dict;
}
