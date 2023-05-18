/*
** EPITECH PROJECT, 2023
** mem_set.c
** File description:
** free
*/

#include "my_utils.h"
#include "my_mem.h"

void * mem_set(void * dst, int c, size_t n)
{
    size_t dstp = (size_t) dst;
    size_t cp;

    if (n >= 8) {

        cp = (unsigned char) c;
        cp |= cp << 8;
        cp |= cp << 16;
        cp |= (cp << 16) << 16;

        n -= dstp % 8;
        BYTE_SET(dstp, c, dstp % 8);

        WORD_SET(dstp, cp, n);
    }

    BYTE_SET(dstp, c, n);

    return dst;
}
