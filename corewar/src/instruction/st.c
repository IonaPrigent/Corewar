/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** st
*/

#include "corewar_proto.h"
#include "core_type.h"
#include "macros.h"

static void store_in_reg(int registers[REG_NUMBER], int value, int reg)
{
    if (!IS_REG(reg))
        return;
    --reg;
    registers[reg] = value;
}

int store(octet_t memory[MEM_SIZE], process_t *process)
{
    octet_t param = PARAMETERS(memory, process->PC);
    int i = 2;
    int register_value = 0;
    int sec_param = 0;

    if (process->wait < 5) return SUCESS;
    if (FSRT_PARAM(param) != PARAM_REG)
        return ERROR;
    register_value = get_value_from_param_ind(memory, FSRT_PARAM(param),
    process->registers, &i);
    if (SECO_PARAM(param) == PARAM_REG) {
        sec_param = memory[(process->PC + i) % MEM_SIZE];
        store_in_reg(process->registers, register_value, sec_param);
    } else {
        sec_param = get_value_from_param_ind(memory, SECO_PARAM(param),
        process->registers, &i);
        place_memory(memory, register_value, sec_param);
    }
    reset_process(process, i);
    return SUCESS;
}
