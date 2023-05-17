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
#include "core_type.h"
#include "op.h"
#include "macros.h"
#include "corewar_proto.h"
#include "my.h"

static int get_nb_processes(int ac, char **av)
{
    int nb_processes = 0;

    for (int i = 0; av[i]; i++) {
        if (my_strcmp(av[i] + (my_strlen(av[i]) - 4), ".cor") == 0)
            nb_processes++;
    }
    return nb_processes;
}

int init_single_process(process_t *all_champ, octet_t arena[MEM_SIZE])
{
    all_champ->wait = 0;
    all_champ->name = 0;
    all_champ->PC = 0;
    all_champ->registers = 0;

}

int init_all(process_t **all_champ, octet_t arena[MEM_SIZE],
int ac, char const *av[])
{
    int nb_process = get_nb_processes(ac, av);
    *all_champ = malloc(sizeof(process_t) * nb_process);

    for (int i = 0; all_champ[i]; i++)
        init_single_process(all_champ[i], arena);

    for (int i = 0; i < MEM_SIZE; ++i) {
        arena[i] = 0;
    }
    return SUCESS;
}
