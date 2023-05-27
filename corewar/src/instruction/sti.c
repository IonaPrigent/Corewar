/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** sti
*/

#include "corewar_proto.h"
#include "corewar_macros.h"
#include "corewar_type.h"
#include "macros.h"

void place_memory(char memory[MEM_SIZE], int value, int idx)
{
    octet_t *list = (octet_t *)&value;

    reverse(&value, sizeof(value));
    if (idx < 0) {
        idx += MEM_SIZE;
    }
    for (int i = 0; i < REG_SIZE; ++i) {
        memory[(idx + i) % MEM_SIZE] = list[i];
    }
}

int store_index(octet_t memory[MEM_SIZE], process_t *process)
{
    octet_t parameters = PARAMETERS(memory, process->PC);
    int index = 0;
    int i = process->PC + 2;
    int reg_id;

    if (process->wait < op_tab[STI].nbr_cycles) return SUCESS;
    if (FSRT_PARAM(parameters) != PARAM_REG)
        return ERROR;
    reg_id = GET_OCTET(memory, i);
    if (!IS_REG(reg_id))
        return ERROR;
    i += REG_LEN;
    index += (short)get_value_from_param_ind(memory, SECO_PARAM(parameters),
    process->registers, &i);
    index += (short)get_value_from_param_ind(memory, THRD_PARAM(parameters),
    process->registers, &i);
    index = (index % IDX_MOD + process->PC) % MEM_SIZE;
    place_memory(memory, process->registers[reg_id - 1], index);
    reset_process(process, i);
    return SUCESS;
}
