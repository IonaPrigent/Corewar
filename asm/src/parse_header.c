/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include "asm.h"

static str_t * valid_info(str_t * line, const char * prefixe, size_t max_len)
{
    AUTOFREE list_str_t * list = NULL;
    str_t * str = NULL;

    if (str_count_char(line->data, '"') != 2)
        return NULL;

    list = split(line, " \t\n", TRUE, TRUE);
    if (list->len != 2)
        return NULL;
    if (str_cmp(list->data[0]->data, prefixe))
        return NULL;

    str = list->data[1];
    if (str->len < 2 || str->len > max_len)
        return NULL;

    if (str->data[0] != '"' || str->data[str->len - 1] != '"')
        return NULL;

    return duplic(str);
}

static header_t * make_header(str_t * name, str_t * comment)
{
    header_t * header = malloc(sizeof(header_t));

    if (header == NULL)
        return NULL;

    delete(name, 0);
    delete(name, name->len);
    delete(comment, 0);
    delete(comment, comment->len);

    mem_set(header, 0, sizeof(header_t));

    header->magic = big_endian(COREWAR_EXEC_MAGIC);
    mem_cpy(header->prog_name, name->data, name->len);
    header->prog_size = big_endian(22);
    mem_cpy(header->comment, comment->data, comment->len);

    return header;
}

header_t * parse_header(list_str_t * text)
{
    AUTOFREE str_t * name = NULL;
    AUTOFREE str_t * comment = NULL;

    if (text->len < 2) {
        return NULL;
    }

    name = valid_info(text->data[0], NAME_CMD_STR, PROG_NAME_LENGTH);
    if (name == NULL) {
        write_error("Invalid programme name");
        return NULL;
    }
    comment = valid_info(text->data[1], COMMENT_CMD_STR, COMMENT_LENGTH);
    if (comment == NULL) {
        write_error("Invalid comment");
        return NULL;
    }

    return make_header(name, comment);
}
