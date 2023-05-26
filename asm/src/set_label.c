/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** op.c for corewar
*/

#include "asm.h"

static size_t get_byte_b4(list_t * cmd, size_t index)
{
    size_t byte = 0;

    for (size_t i = 0; i < index; i++) {
        byte += ((vec_t *) cmd->data[i])->len;
    }

    return byte;
}

static void update_label(list_t * cmd, vec_size_t * lab)
{
    size_t lab_line = lab->data[0];
    size_t byte = 0, line = 0, pos = 0, nbyte = 0;
    vec_t * cmd_byte = NULL;

    for (size_t i = 1; i < lab->len; i += 3) {
        line = lab->data[i];
        pos = lab->data[i + 1];
        nbyte = lab->data[i + 2];
        cmd_byte = cmd->data[line];
        byte = get_byte_b4(cmd, lab_line);
        if (lab_line < line) {
            byte = ((nbyte == 2) ? 0xffff : 0xffffffff)
            - (get_byte_b4(cmd, line) - byte - 1);
        }
        for (size_t n = 0; n < nbyte; n++) {
            cmd_byte->data[pos + n] = ((char *)(&byte))[nbyte - 1 - n];
        }
    }
}

void set_label(list_t * cmd, dict_t * label)
{

    for (size_t x = 0, y; x < label->cap; x++) {
        if (label->buck[x] == NULL || label->buck[x]->len == 0) {
            continue;
        }
        y = 1;
        while (label->buck[x]->len > y) {
            update_label(cmd, label->buck[x]->data[y]);
            y += 2;
        }
    }
}
