/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include "asm.h"

// cmd = list of vec
// vec = bytes of the line

// label = dict[command_name, vec]
// vec[0] = line of the label
// vec[1, 2, 3] = line to insert, position, number of bytes

static int valid_command_name(str_t * name)
{
    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (str_cmp(name->data, op_tab[i].mnemonique) == 0) {
            return op_tab[i].code;
        }
    }
    return -1;
}

static int valid_command_args(list_str_t * args, int op_idx, list_t * cmd,
    dict_t * label)
{
    if (op_tab[op_idx].nbr_args != (char) args->len) {
        dprint(2, "%sWrong number of arguments for the operation \"%s\".\n",
        RED_ERROR, op_tab[op_idx].mnemonique);
        destroy(args);
        return 1;
    }
    for (size_t i = 0; i < args->len; i++) {
        if (valid_arg(args->data[i], (int[2]){op_idx, i}, label, cmd) == 1) {
            destroy(args);
            return 1;
        }
    }
    destroy(args);
    return 0;
}

static int valid_line(list_str_t * line, list_t ** cmd, dict_t * label)
{
    int cmd_code = valid_command_name(line->data[0]);
    AUTOFREE str_t * tmp = NULL;
    vec_t * bytes = NULL;

    if (cmd_code == -1) {
        return 1;
    }
    bytes = VEC(sizeof(char), 10);
    append(&bytes, &cmd_code);
    add_coding_byte(&bytes, cmd_code - 1);
    delete(line, 0);
    tmp = STR("");
    for (size_t i = 0; i < line->len; i++)
        append(&tmp, line->data[i]->data);
    if (valid_command_args(split(tmp, ",", FALSE, FALSE), cmd_code - 1,
    append(cmd, bytes), label) == 1) {
        return 1;
    }
    return 0;
}

static list_t * parse_line(list_str_t * text, dict_t * label)
{
    list_t * cmd = LIST(text->len);
    list_str_t * line = NULL;
    str_t * tmp = NULL;

    for (size_t i = 0; i < text->len; i++) {
        line = split(text->data[i], " \t\n", TRUE, FALSE);
        tmp = line->data[0];
        if (tmp->data[tmp->len - 1] == ':')
            delete(line, 0);
        if (line->len == 0) {
            append(&cmd, VEC(sizeof(char), 0));
            continue;
        }
        if (valid_line(line, &cmd, label))
            return obj_vfree(2, cmd, line);
        destroy(line);
    }
    return cmd;
}

list_t * parse_command(list_str_t * text)
{
    AUTOFREE dict_t * label = get_label(text);
    list_t * cmd = NULL;

    if (label == NULL)
        return NULL;

    cmd = parse_line(text, label);
    if (cmd == NULL)
        return NULL;
    set_label(cmd, label);
    return cmd;
}
