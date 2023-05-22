/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** live
*/

#include "macros.h"
#include "core_type.h"
#include "corewar_proto.h"

int live(octet_t memory[MEM_SIZE], process_t *process)
{
    int i = 1;
    int player_number = 0;

    if (process->wait < 10)
        return SUCESS;
    i += process->PC;
    player_number = get_value_from_dir(memory, &i);
    process->time_left = CYCLE_TO_DIE;
    reset_process(process, i);
}
