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
    int i = process->PC + 1;

    //dprintf(2, "i 1 : %d\n", i);
    if (process->wait < op_tab[ZJUMP].nbr_cycles) {
        return SUCESS;
    }
    if (process->carry != 1) {
        reset_process(process, process->PC + IND_SIZE + 1);
        return SUCESS;
    }

    //index += process->PC
    //dprintf(2, "i 2: %d\n", i);
    dprintf(2, "index 1 : %x\n", index);
    index = (short)GET_MEM_IND(memory, &i);
    dprintf(2, "index 2 : %x\n", index);
    index = process->PC + index % IDX_MOD;
    index %= MEM_SIZE;
    reset_process(process, index);
    return SUCESS;
}
