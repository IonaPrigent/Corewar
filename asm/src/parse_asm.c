/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include "asm.h"

static str_t * read_content(const char * filename)
{
    FILE * file = fopen(filename, "r");
    str_t * text = STR("");
    char char_read[] = " ";

    while (fread(char_read, sizeof(char), 1, file)) {
        append(&text, char_read);
    }

    fclose(file);
    return text;
}

list_str_t * parse_asm(const char * filename)
{
    AUTOFREE str_t * text = read_content(filename);
    AUTOFREE list_str_t * list = split(text, "\n", FALSE, FALSE);
    AUTOFREE list_str_t * lign = split(list->data[0], " \t", TRUE, TRUE);

    print("%o\n\n%o\n", list, lign);

    return NULL;
}
