/*
** EPITECH PROJECT, 2023
** my_def.h
** File description:
** header
*/

#ifndef MY_DEF
    #define MY_DEF

    #include "my_object.h"

    #define AUTOFREE        __attribute__((cleanup(auto_free)))
    #define UNUSED          __attribute__((unused))

    #define STR(str)        create(STR, str)
    #define VEC(type, len)  create(VEC, type, len) // type = sizeof(type)
    #define LIST(len)       create(LIST, len)
    #define DICT(len)       create(DICT, len)

    #define STRN(str, len)  create(STR + 0.1, str, len)

    #define ABS(x)  (((x) < 0) ? -(x) : (x))

    #define TRUE    1
    #define FALSE   0

    #define WHITE   "\033[0m"
    #define RED     "\033[31m"
    #define GREEN   "\033[32m"
    #define YELLOW  "\033[33m"
    #define BLUE    "\033[34m"
    #define RESET   "\033[0m"

#endif /* MY_DEF */
