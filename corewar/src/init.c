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

static void init_empty_process(process_t *process)
{
    process->carry = 0;
    process->name = NULL;
    process->PC = 0;
    process->size = 0;
    process->time_left = 0;
    process->wait = 0;
}

static int init_single_process(process_t *process, char mem[MEM_SIZE], int pc)
{
    header_t *program = malloc(sizeof(header_t));

    init_empty_process(process);
    if (check_magic_number(process->fd, program))
        return 1;
    get_prog_name(process->fd, process);
    get_prog_size(process->fd, process);
    get_program(process->fd, process, mem, pc);
    process->PC = pc;
    process->time_left = CYCLE_TO_DIE;

    for (int i = 0; i < REG_NUMBER; i++) {
        process->registers[i] = 0;
    }
    return SUCESS;
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

char **get_filenames(corewar_t *core, const char *av[])
{
    int a = 0;
    char **filenames = malloc(sizeof(char *) * core->nb_processes + 1);

    for (int i = 0; av[i]; i++) {
        if (my_strcmp(av[i] + (my_strlen(av[i]) - 4), ".cor") == 0) {
            my_strcpy(filenames[a], av[i]);
            core->processes[i].fd = open(filenames[a], O_RDONLY);
            a++;
        }
    }
    filenames[a] = NULL;
    return filenames;
}

int init_all(corewar_t *core, char const *av[])
{
    core->nb_processes = get_nb_processes(av);
    core->nb_original_prog = core->nb_processes;
    core->processes = malloc(sizeof(process_t) * core->nb_processes);
    core->filenames = get_filenames(core, av);
    int space = MEM_SIZE / core->nb_processes;

    if (core->processes == NULL || core->filenames == NULL) {
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
