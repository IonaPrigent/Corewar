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
    process->PC = 0;
    process->time_left = CYCLE_TO_DIE;
    process->wait = 0;
}

static int init_single_process(process_t *process, char mem[MEM_SIZE], int pc,
name_t *name)
{
    header_t header;

    init_empty_process(process);
    read(process->fd, &header, sizeof(header));
    reverse(&header.magic, sizeof(header.magic));
    reverse(&header.prog_size, sizeof(header.prog_size));
    for (int i = 0; i < PROG_NAME_LENGTH + 1; ++i)
        name->name[i] = header.prog_name[i];
    if (header.magic != COREWAR_EXEC_MAGIC)
        return 1;
    get_program(process->fd, process, mem, &header);
    close(process->fd);
    process->PC = pc;
    process->time_left = CYCLE_TO_DIE;
    for (int i = 0; i < REG_NUMBER; i++)
        process->registers[i] = 0;
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

static void get_filedescriptors(corewar_t *core, const char *av[])
{
    int a = 0;

    for (int i = 0; av[i]; i++) {
        if (my_strcmp(av[i] + (my_strlen(av[i]) - 4), ".cor") == 0) {
            core->processes[a].fd = open(av[i], O_RDONLY);
            ++a;
        }
    }
}

int init_all(corewar_t *core, char const *av[])
{
    core->nb_processes = get_nb_processes(av);
    int space = MEM_SIZE / core->nb_processes;
    core->nb_original_prog = core->nb_processes;
    core->processes = malloc(sizeof(process_t) * core->nb_processes);
    core->all_names = malloc(sizeof(name_t) * core->nb_processes);

    get_filedescriptors(core, av);
    if (core->processes == NULL || core->all_names == NULL)
        return ERROR;
    for (int i = 0; i < MEM_SIZE; ++i)
        core->mem[i] = 0;
    for (int i = 0; i < core->nb_processes; ++i) {
        if (core->processes[i].fd == -1)
            return ERROR;
        init_single_process(&(core->processes[i]), core->mem, i * space,
        core->all_names + i);
        core->processes[i].registers[0] = i + 1;
    }
    return SUCESS;
}
