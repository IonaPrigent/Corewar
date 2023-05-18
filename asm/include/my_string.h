/*
** EPITECH PROJECT, 2023
** my_utils.h
** File description:
** header
*/

#ifndef MY_STRING
    #define MY_STRING

    #include <stddef.h>

typedef struct str_s {
    size_t len;
    size_t cap;
    char data[0];
} str_t;

#endif /* MY_STRING */
