/*
** EPITECH PROJECT, 2023
** pad_len.c
** File description:
** utils
*/

#include "my_utils.h"

void free(void * __ptr);

void try_free(void * ptr)
{
    if (ptr != NULL) {
        free(ptr);
    }
}
