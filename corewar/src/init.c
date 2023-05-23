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

static int get_nb_processes(int ac, char const *av[])
{
    int nb_processes = 0;

    for (int i = 0; av[i]; i++) {
        if (my_strcmp(av[i] + (my_strlen(av[i]) - 4), ".cor") == 0)
            nb_processes++;
    }
    return nb_processes;
}

static int init_single_process(process_t *all_champ, octet_t memory[MEM_SIZE],
int a, int pc)
{
    all_champ->wait = 0;
    all_champ->name = 0;
    all_champ->PC = pc;
    all_champ->carry = 0;

    for (int i = 0; all_champ->registers[i]; i++) {
        if (i = 0)
            all_champ->registers[i] = a;
        all_champ->registers[i] = 0;
    }
    return SUCESS;
}

int init_all(process_t **all_champ, octet_t memory[MEM_SIZE],
int ac, char const *av[])
{
    int nb_process = get_nb_processes(ac, av);
    *all_champ = malloc(sizeof(process_t) * nb_process);
    int void_between = MEM_SIZE / nb_process;

    if (*all_champ == NULL) {
        return ERROR;
    }
    for (int i = 0; i < MEM_SIZE; ++i) {
        memory[i] = 0;
    }
    for (int i = 0; i < nb_process; i++)
        init_single_process(all_champ[i], memory, i, i * void_between);

    return SUCESS;
}
