/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include "asm.h"

static int isonlyspace(str_t * str)
{
    const char * space = " \t\n";

    for (size_t i = 0; i < str->len; i++) {
        if (str_chr(space, str->data[i]) == NULL) {
            return 0;
        }
    }
    return 1;
}

static list_str_t * delete_commentary(list_str_t * text)
{
    str_t * line = NULL;

    for (size_t i = 0; i < text->len; i++) {
        line = text->data[i];
        while (str_chr(line->data, '#')) {
            delete(line, line->len);
        }
        if (line->len == 0 || isonlyspace(line)) {
            delete(text, i);
            i--;
        }
    }

    return text;
}

list_str_t * read_content(const char * filename)
{
    FILE * file = fopen(filename, "r");
    AUTOFREE str_t * text = STR("");
    char char_read[] = " ";

    if (file == NULL) {
        write_error("File not found.");
        return NULL;
    }
    while (fread(char_read, sizeof(char), 1, file)) {
        append(&text, char_read);
    }
    fclose(file);

    if (text->len == 0) {
        write_error("Empty file.");
        return NULL;
    }
    return delete_commentary(split(text, "\n", TRUE, FALSE));
}

champ_t * parse_asm(const char * filename)
{
    AUTOFREE list_str_t * text = read_content(filename);
    champ_t * champ = NULL;
    header_t * header = NULL;
    vec_t * command = NULL;

    if (text == NULL)
        return NULL;
    header = parse_header(text);
    if (header == NULL)
        return NULL;
    command = parse_command(text);
    // if (command == NULL) {
    //     free(header);
    //     return NULL;
    // }
    champ = malloc(sizeof(champ_t));
    // header->prog_size = big_endian(command->len); // add len of all line
    champ->hdr = header;
    champ->cmd = command;
    return champ;
}
