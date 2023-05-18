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

// int in_dict(dict_t * dict, char * key, size_t * buff)
// {
//     size_t index = 0;

//     while (index < dict->len) {
//         if (str_cmp(key, dict->item[index]->key->data) == 0) {
//             break;
//         }
//         index += 1;
//     }

//     if (index != dict->len) {
//         if (buff != NULL) {
//             * buff = index;
//         }
//         return 1;
//     }

//     return 0;
// }
