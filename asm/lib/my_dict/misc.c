/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_dict.h"
#include "my_string.h"
#include "my_utils.h"

size_t hash_key(const char * key)
{
    size_t hash = 0;

    while (*key) {
        hash += *key;
        key++;
    }

    return hash;
}

// should call compare instead of strcmp (maybe ?)
int key_in_bucket(const list_t * bucket, const char * key, size_t * buff)
{
    if (bucket->len == 0) {
        return 0;
    }

    for (size_t i = 0; i < bucket->len; i += 2) {
        if (str_cmp(((str_t *) bucket->data[i])->data, key) != 0) {
            continue;
        }
        if (buff != NULL) {
            *buff = i;
        }
        return 1;
    }

    return 0;
}

// not sure if it works well but well do with it
int in_dict(dict_t * dict, char * key, item_t ** buff)
{
    size_t hash = hash_key(key) % dict->cap;
    size_t buck_idx = 0;
    item_t * item = NULL;

    if (dict->buck[hash] == NULL) {
        return 0;
    }

    if (key_in_bucket(dict->buck[hash], key, &buck_idx)) {
        if (buff != NULL) {
            item = malloc(sizeof(item_t));
            item->key = dict->buck[hash]->data[buck_idx];
            item->data = dict->buck[hash]->data[buck_idx + 1];
            *buff = item;
        }
        return 1;
    }

    return 0;
}
