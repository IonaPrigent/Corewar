/*
** EPITECH PROJECT, 2023
** my_def.h
** File description:
** header
*/

#ifndef MY_DEF
    #define MY_DEF

    #include "my_object.h"

    #define UNUSED __attribute__((unused))
    #define AUTOFREE __attribute__((cleanup(auto_free)))

    #define STR(s)      create(STR, s)
    #define VEC(t, n)   create(VEC, t, n)
    #define LIST(n)     create(LIST, n)
    #define DICT(n)     create(DICT, n)

    #define TOSTR(c) ((char[]){c, '\0'})
    #define ABS(x) (((x) < 0) ? -(x) : (x))

#endif /* MY_DEF */
