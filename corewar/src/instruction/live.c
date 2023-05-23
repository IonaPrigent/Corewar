/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** live
*/

#include "macros.h"
#include "corewar_macros.h"
#include "corewar_type.h"
#include "corewar_proto.h"

int live(octet_t memory[MEM_SIZE], process_t *process)
{
    int i = 1;
    direct_t player_number;
    corewar_t *core = corewar_store();

    if (process->wait < 10)
        return SUCESS;
    i += process->PC;
    player_number = GET_MEM_DIR(memory, &i);
    for (int i = 0; i < core->nb_original_prog; ++i) {

    }
    for (int i = 0; i < core->nb_processes; ++i) {
        if (core->processes[i].registers[0] == player_number) {
            core->processes[i].time_left = CYCLE_TO_DIE;
        }
    }
    reset_process(process, 5);
    return SUCESS;
}
