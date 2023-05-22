/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** parse_cor_file
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include "op.h"

int check_magic_number(int fd, header_t *program)
{
    char c;
    char magic_number[4];

    for (int i = 0; read(fd, &c, 1) != 1 && i < 4; i++)
        magic_number[i] = c;
    program->magic = magic_number;
    free(magic_number);
    if (my_strcmp(magic_number, "00 ea 83 f3") == 0)
        return 0;
    return 1;
}

int get_prog_name(int fd, header_t *program)
{
    char c;
    char p_name[PROG_NAME_LENGTH + 1];

    for (int i = 0; read(fd, &c, 1) != 1 && i <= PROG_NAME_LENGTH; i++)
        p_name[i] = c;

    program->prog_name = p_name;
    free(p_name);

    return 0;
}

int get_prog_size(int fd, header_t *program)
{
    char c;
    char p_size[4];

    for (int i = 0; read(fd, &c, 1) != 1 && i < 4; i++)
        p_size[i] = c;
    program->prog_size = p_size;
    free(p_size);
    return 0;
}

int get_program(int fd, header_t *program)
{
    char c;
    char p_core[program->prog_size];

    for (int i = 0; read(fd, &c, 1) != 1 && i < program->prog_size; i++)
        p_core[i] = c;
    program->prog_size = p_core;
    free(p_core);
    return 0;
}