/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** init
*/

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include "corewar_macros.h"
#include "corewar_type.h"
#include "op.h"
#include "macros.h"
#include "corewar_proto.h"
#include "my.h"

static char **parse_cor_file(char *filename)
{
    header_t *program = malloc(sizeof(header_t));
    int fd = open(filename, O_RDONLY);

    if (fd == -1 || check_magic_number(fd, program))
        return NULL;
    get_prog_name(fd, program);
    get_prog_size(fd, program);
    get_program(fd, program);

    return NULL;
}

static int get_nb_processes(char const *av[])
{
    int nb_processes = 0;

    for (int i = 0; av[i]; i++) {
        if (my_strcmp(av[i] + (my_strlen(av[i]) - 4), ".cor") == 0)
            nb_processes++;
    }
    return nb_processes;
}

static int init_single_process(process_t *process, char [MEM_SIZE], int pc)
{
    process->wait = 0;
    process->name = 0;
    process->PC = pc;
    process->carry = 0;

    for (int i = 0; i < REG_NUMBER; i++) {
        process->registers[i] = 0;
    }
    return SUCESS;
}

int init_all(corewar_t *core, char const *av[])
{
    core->nb_processes = get_nb_processes(av);
    core->nb_original_prog = core->nb_processes;
    core->processes = malloc(sizeof(process_t) * core->nb_processes);
    core->filenames = malloc(sizeof(char *) * core->nb_processes);
    int space = MEM_SIZE / core->nb_processes;

    if (core->processes == NULL) {
        return ERROR;
    }
    for (int i = 0; i < MEM_SIZE; ++i) {
        core->mem[i] = 0;
    }
    for (int i = 0; i < core->nb_processes; i++) {
        init_single_process(&(core->processes[i]), core->mem, i * space);
    }
    return SUCESS;
}
