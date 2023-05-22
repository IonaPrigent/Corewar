/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include "asm.h"

list_str_t * read_content(const char * filename)
{
    FILE * file = fopen(filename, "r");
    str_t * text = STR("");
    char char_read[] = " ";

    if (file == NULL) {
        destroy(text);
        write_error("in function fopen: File not found.\n");
        return NULL;
    }

    while (fread(char_read, sizeof(char), 1, file)) {
        append(&text, char_read);
    }

    fclose(file);
    return split(text, "\n", FALSE, FALSE);
}

static int valid_info(list_str_t * list, const char * prefixe, size_t max_len)
{
    str_t * str = NULL;

    if (list->len != 2)
        return 1;

    str = list->data[1];

    if (str_cmp(list->data[0]->data, prefixe))
        return 1;

    if (str->len < 2 || str->len > max_len)
        return 1;

    if (str->data[0] != '"' || str->data[str->len - 1] != '"')
        return 1;

    return 0;
}

static header_t * make_header(const str_t * name, const str_t * comment)
{
    header_t * header = malloc(sizeof(header_t));

    if (header == NULL)
        return NULL;

    mem_set(header->prog_name, 0, sizeof(header->prog_name));
    mem_cpy(header->prog_name, name->data + 1, name->len - 2);
    mem_set(header->comment, 0, sizeof(header->comment));
    mem_cpy(header->comment, comment->data + 1, comment->len - 2);

    header->magic = big_endian(COREWAR_EXEC_MAGIC);
    header->prog_size = big_endian(22);

    return header;
}

static header_t * get_header(list_str_t * list, size_t * index)
{
    AUTOFREE list_str_t * name = NULL;
    AUTOFREE list_str_t * comment = NULL;
    size_t i = 0;

    for (; i < list->len && list->data[i]->len == 0; i++);
    if (i == list->len)
        return NULL;
    name = split(list->data[i], " \t\n", TRUE, TRUE);
    if (valid_info(name, NAME_CMD_STR, PROG_NAME_LENGTH) == 1)
        return destroy(name);
    for (i++; i < list->len && list->data[i]->len == 0; i++);
    if (i == list->len)
        return NULL;
    comment = split(list->data[i], " \t\n", TRUE, TRUE);
    if (valid_info(comment, COMMENT_CMD_STR, COMMENT_LENGTH) == 1)
        return NULL;
    *index = i;
    return make_header(name->data[1], comment->data[1]);
}

champ_t * parse_asm(const char * filename)
{
    AUTOFREE list_str_t * text = read_content(filename);
    champ_t * champ = NULL;
    header_t * header = NULL;
    vec_t * command = NULL;
    size_t index = 0;

    if (text == NULL)
        return NULL;
    header = get_header(text, &index);
    if (header == NULL)
        return NULL;
    // // command = get_command(text, index);
    // if (command == NULL) {
    //     free(header);
    //     return NULL;
    // }
    champ = malloc(sizeof(champ_t));
    champ->hdr = header;
    champ->cmd = command;
    return champ;
}
