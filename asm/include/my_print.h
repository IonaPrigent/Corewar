/*
** EPITECH PROJECT, 2023
** my_utils.h
** File description:
** header
*/

#ifndef MY_PRINT
    #define MY_PRINT

    #include "my_object.h"
    #include "my_def.h"

typedef struct formater_s {
    char type;
    void (* add) (str_t **, va_list);
} formater_t;

size_t print(const char * str, ...);

#endif /* MY_PRINT */
