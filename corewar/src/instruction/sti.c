/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** sti
*/

#include "core_type.h"
#include "macros.h"

static void place_memory(char memory[MEM_SIZE], int value, int idx)
{
    int cache = 0xff;

    for (int i = 0; i < REG_SIZE; ++i) {
        memory[idx + i] = value >> (3 - i) * sizeof(octet_t) & cache;
    }
}

int sti(char memory[MEM_SIZE], process_t *process)
{
    octet_t parameters = memory[process->PC + 1];
    int index = process->PC;
    int value = 0;
    int i = 2;

    if (FSRT_PARAM(parameters) != PARAM_REG) {
        return ERROR;
    }
    value = process->registers[memory[process->PC + i] - 1];
    i += T_REG;
    switch (SECO_PARAM(parameters)) {
    case PARAM_REG:
        index += process->registers[memory[process->PC + i] - 1];
        i += T_REG;
        break;
    case PARAM_IND:
        i += IND_SIZE;
        break;
    default:
        break;
    }
    return SUCESS;
}
