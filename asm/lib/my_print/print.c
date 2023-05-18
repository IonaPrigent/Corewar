/*
** EPITECH PROJECT, 2023
** mem_cpy.c
** File description:
** utils
*/

#include <unistd.h>

#include "my_print.h"

void add_chr(str_t ** str, va_list ap);
void add_str(str_t ** str, va_list ap);
void add_int(str_t ** str, va_list ap);
void add_flt(str_t ** str, va_list ap);
void add_obj(str_t ** str, va_list ap);

static const formater_t FORMAT[] = {
    { 'c', &add_chr },
    { 's', &add_str },
    { 'd', &add_int },
    { 'f', &add_flt },
    { 'o', &add_obj },
};

// this only work because of little endian encoding (i think).
// since the append function will consider the int as an array of char
// since the first byte is the value and the second is a 0 ('\0').
// this works
static void add_element(str_t ** str, va_list ap, char type)
{
    int i = 0;

    if (type == '%') {
        append(str, TOSTR(va_arg(ap, int)));
        return;
    }

    for (; FORMAT[i].type != type; i++);

    FORMAT[i].add(str, ap);
}

static void parse_format(const char * format, str_t ** str, va_list ap)
{
    while (*format) {
        if (*format == '%') {
            format += 1;
            add_element(str, ap, *format);
        } else {
            append(str, TOSTR(*format));
        }
        format += 1;
    }
}

size_t print(const char * format, ...)
{
    AUTOFREE str_t * str = create(STR, "");
    va_list ap;

    va_start(ap, format);
    parse_format(format, &str, ap);
    va_end(ap);

    write(STDOUT_FILENO, str->data, str->len);

    return str->len;
}
