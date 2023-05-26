/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** op.c for corewar
*/

#include "asm.h"

static int is_valid_reg(str_t * arg, list_t * cmd, int * op_info)
{
    int nbr = 0;
    int i = op_info[1];
    op_t * op = &(op_tab[op_info[0]]);

    if (!is_number(arg->data + 1, 0)) {
        write_error("Invalid register value. (you wrote shit)");
        return 1;
    }
    nbr = my_atoi(arg->data + 1);
    if (nbr < 1 || nbr > 16) {
        write_error("Invalid register, the value must be between 1 and 16.");
        return 1;
    }
    if (has_coding_byte(op->mnemonique)) {
        ((vec_t *) cmd->data[cmd->len - 1])->data[1] |= 0b01000000 >> (2 * i);
    }
    append(&(cmd->data[cmd->len - 1]), &nbr);
    return 0;
}

static int is_valid_label(char * str, dict_t * label, list_t * cmd,
    size_t size)
{
    list_t * buck = NULL;
    size_t hash = hash_key(str) % label->cap;
    size_t index = 0;

    if (in_dict(label, str, NULL)) {
        buck = label->buck[hash];
        key_in_bucket(buck, str, &index);
        append(&(buck->data[index + 1]), (size_t[]){cmd->len - 1});
        append(&(buck->data[index + 1]),
        &(((vec_t *) cmd->data[cmd->len - 1])->len));
        append(&(buck->data[index + 1]), &size);
        for (size_t i = 0; i < size; i++) {
            append(&(cmd->data[cmd->len - 1]), (size_t[]){0});
        }
        return 0;
    }
    return 1;
}

static int is_valid_dir(str_t * arg, int * op_info, dict_t * label,
    list_t * cmd)
{
    int nbr = 0;
    char byte = 0;
    op_t * op = &(op_tab[op_info[0]]);
    size_t isindex = is_index(op->mnemonique);
    int i = op_info[1];

    if (has_coding_byte(op->mnemonique))
        ((vec_t *) cmd->data[cmd->len - 1])->data[1] |= 0b10000000 >> (2 * i);
    if (arg->data[1] == ':')
        return is_valid_label(arg->data + 2, label, cmd, isindex);
    if (!is_number(arg->data + 1, 0)) {
        write_error("Invalid direct value. (you wrote shit)");
        return 1;
    }
    nbr = my_atoi(arg->data + 1);
    for (size_t i = 0; i < isindex; i++) {
        byte = (nbr >> ((isindex - 1 - i) * 8)) & 0xff;
        append(&(cmd->data[cmd->len - 1]), &byte);
    }
    return 0;
}

static int is_valid_ind(str_t * arg, int * op_info, dict_t * label,
    list_t * cmd)
{
    int nbr = 0;
    char byte = 0;
    op_t * op = &(op_tab[op_info[0]]);
    int i = op_info[1];

    if (has_coding_byte(op->mnemonique))
        ((vec_t *) cmd->data[cmd->len - 1])->data[1] |= 0b11000000 >> (2 * i);
    if (arg->data[0] == ':')
        return is_valid_label(arg->data + 2, label, cmd, 2);
    if (!is_number(arg->data, 0)) {
        write_error("Invalid indirect value. (you wrote shit)");
        return 1;
    }
    nbr = my_atoi(arg->data);
    for (int i = 0; i < 2; i++) {
        byte = (nbr >> ((1 - i) * 8)) & 0xff;
        append(&(cmd->data[cmd->len - 1]), &byte);
    }
    return 0;
}

int valid_arg(str_t * arg, int * op_info, dict_t * label, list_t * cmd)
{
    printf(":%s:\n", op_tab[op_info[0]].mnemonique);
    if (arg->data[0] == 'r') {
        if (!(op_tab[op_info[0]].type[op_info[1]] & T_REG)) {
            write_error("The instruction does not support registers.");
            return 1;
        }
        return is_valid_reg(arg, cmd, op_info);
    }
    if (arg->data[0] == '%') {
        if (!(op_tab[op_info[0]].type[op_info[1]] & T_DIR)) {
            write_error("The instruction does not support directs.");
            return 1;
        }
        return is_valid_dir(arg, op_info, label, cmd);
    }
    if (!(op_tab[op_info[0]].type[op_info[1]] & T_IND)) {
        write_error("The instruction does not support indirects.");
        return 1;
    }
    return is_valid_ind(arg, op_info, label, cmd);
}
