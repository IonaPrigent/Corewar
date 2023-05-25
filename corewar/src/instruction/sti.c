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
    int cache = 0xff;

    for (int i = 0; i < REG_SIZE; ++i) {
        memory[idx + i % MEM_SIZE] = value >> (3 - i) * sizeof(octet_t) & cache;
    }
}

int store_index(octet_t memory[MEM_SIZE], process_t *process)
{
    octet_t parameters = PARAMETERS(memory, process->PC);
    int index = 0;
    int value = 0;
    int i = 2;

    if (process->wait < 25)
        return SUCESS;
    if (FSRT_PARAM(parameters) != PARAM_REG)
        return ERROR;
    value = process->registers[memory[process->PC + i] - 1];
    i += REG_LEN;
    index += get_value_from_param_ind(memory, SECO_PARAM(parameters),
    process->registers, &i);
    dprintf(2, "param :%hhx\n", index);
    index += get_value_from_param_ind(memory, THRD_PARAM(parameters),
    process->registers, &i);
    index = (index % IDX_MOD + process->PC) % MEM_SIZE;
    place_memory(memory, value, index);
    reset_process(process, i);
    return SUCESS;
}
