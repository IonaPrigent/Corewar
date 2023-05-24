/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** op.c for corewar
*/

#include "asm.h"

char * indexes[] = {
    "zjmp",
    "ldi",
    "sti",
    "fork"
};

static int is_valid_reg(str_t * arg, char type, list_t * cmd)
{
    int nbr = 0;

    if (!(type & T_REG)) {
        write_error("The instruction does not support registers.");
        return 1;
    }
    if (!is_number(arg->data + 1, 0)) {
        write_error("Invalid register value. (you wrote shit)");
        return 1;
    }
    nbr = my_atoi(arg->data + 1);
    if (nbr < 1 || nbr > 16) {
        write_error("Invalid register, the value must be between 1 and 16.");
        return 1;
    }
    append(&(cmd->data[cmd->len - 1]), &nbr);
    return 0;
}

// size is for dir/indirect/index size = array with index
static int is_valid_label(char * str, dict_t * label, list_t * cmd,
    size_t size)
{
    list_t * buck = NULL;
    size_t hash = hash_key(str) % label->cap;
    size_t index = 0;

    if (in_dict(label, str, NULL)) {
        buck = label->buck[hash];
        index = key_in_bucket(buck, str, &index);
        append(&(buck->data[index + 1]), &(cmd->len));
        append(&(buck->data[index + 1]), &(((vec_t *) cmd->data)->len));
        append(&(buck->data[index + 1]), &(size));
        for (size_t i = 0; i < size; i++) {
            append(&(cmd->data[cmd->len - 1]), NULL);
        }
        return 0;
    }
    return 1;
}

static size_t is_index(const char * str)
{
    for (int i = 0; i < 4; i++) {
        if (str_cmp(str, indexes[i]) == 0) {
            return 2;
        }
    }
    return 4;
}

static int is_valid_dir(str_t * arg, char type, dict_t * label, list_t * cmd)
{
    int nbr = 0;
    char byte = 0;

    if (!(type & T_DIR)) {
        write_error("The instruction does not support directs.");
        return 1;
    }
    if (arg->data[1] == ':') {
        return is_valid_label(arg->data + 2, label, cmd,
        is_index(arg->data + 2));
    }
    if (!is_number(arg->data + 1, 0)) {
        write_error("Invalid direct value. (you wrote shit)");
        return 1;
    }
    nbr = my_atoi(arg->data + 1);
    for (size_t i = 0; i < is_index(arg->data + 2); i++) {
        byte = (nbr >> ((3 - i) * 8)) & 0xff;
        append(&(cmd->data[cmd->len - 1]), &byte);
    }
    return 0;
}

static int is_valid_ind(str_t * arg, char type, dict_t * label, list_t * cmd)
{
    int nbr = 0;
    char byte = 0;

    if (!(type & T_IND)) {
        write_error("The instruction does not support indirects.");
        return 1;
    }
    if (arg->data[0] == ':') {
        return is_valid_label(arg->data + 2, label, cmd, 2);
    }
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

int valid_arg(str_t * arg, char type, dict_t * label, list_t * cmd)
{
    char c = arg->data[0];

    if (c == 'r')
        return is_valid_reg(arg, type, cmd);
    else if (c == '%')
        return is_valid_dir(arg, type, label, cmd);
    else
        return is_valid_ind(arg, type, label, cmd);
    return 0;
}
