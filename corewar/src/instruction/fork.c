/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** fork
*/
#include "macros.h"
#include "corewar_macros.h"
#include "corewar_type.h"
#include "corewar_proto.h"

#include <stdlib.h>

int fork(octet_t mem[MEM_SIZE], process_t *process)
{
    corewar_t *core = corewar_store();

    core->nb_processes += 1;
    core->processes = realloc(core->processes,
    sizeof(process_t) * core->nb_processes);
    if (core->processes == NULL) {
        return ERROR;
    }
    core->processes[core->nb_processes - 1] = *process;
    return SUCESS;
}
