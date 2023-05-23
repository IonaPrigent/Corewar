/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** parse_cor_file
*/

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "op.h"
#include "macros.h"
#include "corewar_type.h"

int check_magic_number(int fd, header_t *program)
{
    char c;
    char first_octet[4];

    for (int i = 0; read(fd, &c, 1) != 1 && i < 4; ++i)
        first_octet[i] = c;
    for (int i = 0; i < 4; ++i) {
        program->magic <<= 8;
        program->magic += first_octet[i];
    }
    if (program->magic == COREWAR_EXEC_MAGIC)
        return SUCESS;
    return ERROR;
}

int get_prog_name(int fd, process_t *process)
{
    char c;
    char p_name[PROG_NAME_LENGTH + 1];

    for (int i = 0; read(fd, &c, 1) != 1 && i <= PROG_NAME_LENGTH; i++)
        p_name[i] = c;
    for (int i = 0; i < PROG_NAME_LENGTH + 1; ++i) {
        process->name[i] = p_name[i];
    }
    return 0;
}

int get_prog_size(int fd, process_t *process)
{
    char c;
    char size_octet[4];

    for (int i = 0; read(fd, &c, 1) != 1 && i < 4; ++i)
        size_octet[i] = c;
    for (int i = 0; i < 4; ++i) {
        process->size <<= 8;
        process->size += size_octet[i];
    }
    return SUCESS;
}

int get_program(int fd, process_t *process, char mem[MEM_SIZE], int pc)
{
    char c;

    for (int i = 0; read(fd, &c, 1) != 1 && i < process->size; ++i)
        mem[(pc + i) % MEM_SIZE] = c;

    return 0;
}
