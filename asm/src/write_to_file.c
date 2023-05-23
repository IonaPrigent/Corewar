/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** op.c for corewar
*/

#include "asm.h"

int write_header(const char * filename, header_t * header)
{
    AUTOFREE str_t * str = STR(filename);
    FILE * file = NULL;

    while (str_chr(str->data, '.')) {
        delete(str, str->len);
    }
    append(&str, ".cor");

    file = fopen(str->data, "w");
    if (file == NULL)
        return ERROR;
    fwrite(header, sizeof(header_t), 1, file);
    fclose(file);

    return SUCCESS;
}
