/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_object.h"
#include "my_utils.h"

void * vec_resize(void ** ptr, size_t new_cap);

void * vec_insert(void ** ptr, va_list ap)
{
    vec_t * vec = * ptr;
    size_t index = va_arg(ap, size_t);
    void * data = va_arg(ap, void *);

    if (vec->len == vec->cap) {
        vec = vec_resize(ptr, vec->cap + 1);
    }

    if (index < vec->len) {
        for (size_t n = (vec->len + 1) * vec->size_data - 1;
            n >= (index + 1) * vec->size_data; n--) {
                vec->data[n] = vec->data[n - vec->size_data];
        }
    } else if (index > vec->len) {
        index = vec->len;
    }

    mem_cpy(vec->data + index * vec->size_data, data, vec->size_data);
    vec->len += 1;

    return vec;
}
