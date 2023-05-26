/*
** EPITECH PROJECT, 2023
** my_utils.h
** File description:
** header
*/

#ifndef MY_DICT
    #define MY_DICT

    #include <stddef.h>

    #include "my_list.h"

typedef struct dict_s {
    size_t cap;
    list_t * buck[0];
} dict_t;

typedef struct item_s {
    str_t * key;
    void * data;
} item_t;

/**
 * @brief hash a key
 *
 * @param key key to hash
 *
 * @return the hashed key
*/
size_t hash_key(const char * key);

/**
 * @brief check if a dict bucket contain a key.
 * put the index in buff if possible.
 *
 * @param bucket bucket to check
 * @param key key to check
 * @param buff buffer for the index found
 *
 * @return 1 or 0
*/
int key_in_bucket(const list_t * bucket, const char * key, size_t * buff);

/**
 * @brief check if a dict contain a key. put the item[key, data] into
 * buff if buff non-NULL. (do not free the item)
 *
 * @param dict target dict
 * @param key key to check
 * @param buff buffer for the item
 *
 * @return 1 or 0
*/
int in_dict(dict_t * dict, char * key, item_t ** buff);

#endif /* MY_DICT */
