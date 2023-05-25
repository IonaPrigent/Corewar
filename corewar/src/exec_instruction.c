/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** exec_instruction
*/

#include "corewar_type.h"
#include "macros.h"
#include "corewar_proto.h"
#include "corewar_macros.h"
#include "op.h"
#include "instruction.h"
#include <stdbool.h>

bool is_finished(corewar_t *core)
{
    int id_champ_alive = 0;
    bool champ_alive_detected = false;

    for (int i = 0; i < core->nb_processes; ++i) {
        if (core->processes[i].time_left > 0
        && champ_alive_detected == true
        && core->processes[i].registers[0] != id_champ_alive) {
            return false;
        }
        if (core->processes[i].time_left > 0
        && champ_alive_detected == false) {
            champ_alive_detected = true;
            id_champ_alive = core->processes[i].registers[0];
        }
    }
    return true;
}

int exec_instruction(corewar_t *core, process_t *process)
{
    octet_t instruction = core->mem[process->PC];

    process->wait += 1;
    process->time_left -= 1;
    if (!IS_INSTRUCTION(instruction)) {
        process->PC = (process->PC + 1) % MEM_SIZE;
        return SUCESS;
    }
    all_instruction[(int)instruction - 1](core->mem, process);
    return SUCESS;
}

int run_corewar(corewar_t *core, long dump)
{
    long i = 0;

    dprintf(2, "aze\n%d\n", is_finished(core));
    for (; i != dump && is_finished(core) == false ; ++i) {
        if (i < 0)
            i = 0;
        for (int j = 0; j < core->nb_processes; ++j) {
            exec_instruction(core, &(core->processes[j]));
        }
    }
    if (i == dump) {
        display_memory(core->mem);
    }
    return 0;
}
