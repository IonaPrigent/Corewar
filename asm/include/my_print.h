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

    #define TOSTR(c)    ((char[]){c, '\0'})

typedef struct formater_s {
    char type;
    void (* add) (str_t **, va_list);
} formater_t;

size_t print(const char * str, ...);
size_t dprint(int fd, const char * format, ...);

void write_fd(int fd, const char * str);
void write_error(const char * str);
void write_line_error(const char * str, int line);

#endif /* MY_PRINT */
