/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** zjmp
*/

#include "corewar_proto.h"
#include "corewar_type.h"
#include "macros.h"
#include "corewar_macros.h"

int zjump(octet_t memory[MEM_SIZE], process_t *process)
{
    int index = 0;

    if (process->wait < 20) {
        return SUCESS;
    }
    if (process->carry != 1) {
        reset_process(process, 3);
        return SUCESS;
    }
    index = GET_MEM_IND(memory, process->PC + 1);
    index = process->PC + index % IDX_MOD;
    index %= MEM_SIZE;
    process->PC = index;
    return SUCESS;
}
