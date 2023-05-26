/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** op.c for corewar
*/

#include <unistd.h> // pour ambroise sinon il va sérer. -> write

#include "asm.h"

static void write_cmd(list_t * cmd, FILE * file)
{
    vec_t * line = NULL;

    for (size_t i = 0; i < cmd->len; i++) {
        line = cmd->data[i];
        if (line->len > 0) {
            fwrite(line->data, sizeof(char), line->len, file);
        }
    }
}

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
    write_cmd(champ->cmd, file);

    fclose(file);
    return SUCCESS;
}
