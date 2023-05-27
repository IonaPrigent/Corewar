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



int fork_fct(octet_t mem[MEM_SIZE], process_t *process)
{
    corewar_t *core = corewar_store();
    int i = process->PC + 1;
    int index = GET_MEM_IND(mem, &i);
    process_t tmp;

    if (process->wait < op_tab[FORK].nbr_cycles)
        return SUCESS;
    copy(&tmp, process, sizeof(process_t));
    reset_process(process, i);
    core->nb_processes += 1;
    core->processes = realloc(core->processes,
    sizeof(process_t) * core->nb_processes);
    if (core->processes == NULL)
        return ERROR;
    copy(&core->processes[core->nb_processes - 1], &tmp, sizeof(process_t));
    core->processes[core->nb_processes - 1].wait = 0;
    core->processes[core->nb_processes - 1].PC = tmp.PC + index % IDX_MOD;
    core->processes[core->nb_processes - 1].PC %= MEM_SIZE;
    return SUCESS;
}
