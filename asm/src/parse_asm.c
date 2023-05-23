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
    return split(text, "\n", TRUE, FALSE);
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
    champ = malloc(sizeof(champ_t));
    champ->hdr = header;
    champ->cmd = command;
    return champ;
}
    // // command = get_command(text);
    // if (command == NULL) {
    //     free(header);
    //     return NULL;
    // }
