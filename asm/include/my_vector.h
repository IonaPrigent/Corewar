/*
** EPITECH PROJECT, 2023
** my_utils.h
** File description:
** header
*/

#ifndef MY_VEC
    #define MY_VEC

    #include <stddef.h>

    #define VEC_DEF(type, name)     \
                                    \
    typedef struct vec##name##_s { \
        int size_data;              \
        size_t len;                 \
        size_t cap;                 \
        type data[0];               \
    } vec##name##_t;               \

VEC_DEF(char,)
VEC_DEF(int, _int)
VEC_DEF(float, _float)
VEC_DEF(size_t, _size)
VEC_DEF(double, _double)

#endif /* MY_VEC */
