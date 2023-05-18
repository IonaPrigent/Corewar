/*
** EPITECH PROJECT, 2023
** pad_len.c
** File description:
** utils
*/

#include <stdarg.h>

#include "my_utils.h"

void free(void * __ptr);

void vfree(size_t n, ...)
{
    va_list ap;

    va_start(ap, n);
    while (n--) {
        try_free(va_arg(ap, void *));
    }
    va_end(ap);
}
