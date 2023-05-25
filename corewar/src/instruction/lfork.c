/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** lfork
*/
#include "macros.h"
#include "corewar_macros.h"
#include "corewar_type.h"
#include "corewar_proto.h"

#include <stdlib.h>

int lfork(octet_t mem[MEM_SIZE], process_t *process)
{
    corewar_t *core = corewar_store();
    int i = process->PC + 1;
    int index = GET_MEM_IND(mem, &i);

    core->nb_processes += 1;
    core->processes = realloc(core->processes,
    sizeof(process_t) * core->nb_processes);
    if (core->processes == NULL) {
        return ERROR;
    }
    copy(&core->processes[core->nb_processes - 1], process, sizeof(process_t));
    core->processes[core->nb_processes - 1].wait = 0;
    core->processes[core->nb_processes - 1].PC = process->PC + index;
    core->processes[core->nb_processes - 1].PC %= MEM_SIZE;
    return SUCESS;
}
