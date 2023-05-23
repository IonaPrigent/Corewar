/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** op.c for corewar
*/

#include "asm.h"

int write_champ(const char * filename, champ_t * champ)
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

    fwrite(champ->hdr, sizeof(header_t), 1, file);
    // fwrite(champ->cmd, sizeof(char), champ->cmd->len, file);

    fclose(file);
    return SUCCESS;
}
