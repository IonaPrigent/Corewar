/*
** EPITECH PROJECT, 2023
** create_str.c
** File description:
** create a str_t (string)
*/

#include "my_utils.h"

// could split at every char if sep is empty
list_str_t * split(str_t * str, const char * sep, int clean, int keepquote)
{
    list_str_t * list = LIST(5);
    size_t last_idx = 0;
    int inquote = FALSE;

    for (size_t i = 0; i <= str->len; i++) {
        inquote = (str->data[i] == '"' && keepquote) ? TRUE : FALSE;
        if (i == str->len || (str_chr(sep, str->data[i]) && inquote == FALSE)) {
            append(&list, STRN(str->data + last_idx, i - last_idx));
            last_idx = i + 1;
        }
    }

    return (clean == TRUE) ? filter(list) : list;
}
