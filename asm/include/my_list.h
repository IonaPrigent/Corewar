/*
** EPITECH PROJECT, 2023
** my_utils.h
** File description:
** header
*/

#ifndef MY_LIST
    #define MY_LIST

    #include <stddef.h>

    #include "my_string.h"

typedef struct list_s {
    size_t len;
    size_t cap;
    void * data[0];
} list_t;

typedef struct list_str_s {
    size_t len;
    size_t cap;
    str_t * data[0];
} list_str_t;

#endif /* MY_LIST */
