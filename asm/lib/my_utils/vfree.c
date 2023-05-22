/*
** EPITECH PROJECT, 2023
** pad_len.c
** File description:
** utils
*/

#include <stdarg.h>

#include "my_object.h"
#include "my_utils.h"

void vfree(size_t n, ...)
{
    va_list ap;

    va_start(ap, n);
    while (n--) {
        try_free(va_arg(ap, void *));
    }
    va_end(ap);
}

void obj_vfree(size_t n, ...)
{
    va_list ap;

    va_start(ap, n);
    while (n--) {
        destroy(va_arg(ap, void *));
    }
    va_end(ap);
}
