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

int get_program(int fd, process_t *process, char mem[MEM_SIZE], int pc)
{
    char c;

    for (int i = 0; i < process->size && read(fd, &c, 1) == 1; ++i) {
        mem[(pc + i) % MEM_SIZE] = c;
    }
    return 0;
}
