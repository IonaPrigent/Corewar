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
#include "my.h"

int get_program(int fd, process_t *process, char mem[MEM_SIZE],
header_t *header)
{
    char prog[header->prog_size];

    if (read(fd, prog, header->prog_size) == -1)
        return 0;
    for (int i = 0; prog[i]; ++i) {
        mem[(process->PC + i) % MEM_SIZE] = prog[i];
    }
    return 0;
}
