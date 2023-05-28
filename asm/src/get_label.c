/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include "asm.h"

static int valid_label(dict_t * dict, str_t * label)
{
    for (size_t i = 0; i < label->len; i++) {
        if (str_chr(LABEL_CHARS, label->data[i]) == NULL) {
            dprint(2, "%sInvalid label name: %o\n", RED_ERROR, label);
            return 0;
        }
    }

    if (in_dict(dict, label->data, NULL)) {
        dprint(2, "%sMultiple definition of the same label: %o\n", RED_ERROR,
        label);
        return 0;
    }
    return 1;
}

dict_t * get_label(list_str_t * text)
{
    dict_t * dict = DICT(4);
    list_str_t * line = NULL;
    vec_long_t * vec = NULL;

    for (size_t i = 0; i < text->len; i++) {
        if (str_chr(text->data[i]->data, ':') == NULL)
            continue;
        line = split(text->data[i], " \t\n", TRUE, FALSE);
        if (line->data[0]->data[line->data[0]->len - 1] != ':') {
            destroy(line);
            continue;
        }
        if (valid_label(dict, delete(line->data[0], line->data[0]->len))) {
            vec = VEC(sizeof(long), 4);
            append(&vec, &i); append(&dict, line->data[0]->data, vec);
            destroy(line);
        } else
            return obj_vfree(2, dict, line);
    }
    return dict;
}
