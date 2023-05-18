/*
** EPITECH PROJECT, 2023
** mem_cpy.c
** File description:
** utils
*/

#include "my_utils.h"
#include "my_mem.h"

void * mem_cpy(void * dst, const void * src, size_t n)
{
    size_t dstp = (size_t) dst;
    size_t srcp = (size_t) src;

    if (n >= 8) {
        n -= dstp % 8;
        BYTE_COPY(dstp, srcp, dstp % 8);

        WORD_COPY(dstp, srcp, n);
    }

    BYTE_COPY(dstp, srcp, n);

    return dst;
}
