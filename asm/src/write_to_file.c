/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** op.c for corewar
*/

#include "asm.h"

void write_header(FILE * file, header_t * header)
{
    fwrite(header, sizeof(header_t), 1, file);
}
