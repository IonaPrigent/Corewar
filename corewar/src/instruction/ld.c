/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** ld
*/

#include "corewar_proto.h"
#include "core_type.h"
#include "macros.h"

int load(octet_t memory[MEM_SIZE], process_t *process)
{
    int index = 0;
    int i = 2;
    int num_reg = 0;
    octet_t param = PARAMETERS(memory, process->PC);

    if (process->wait < 5)
        return SUCESS;
    if (SECO_PARAM(param) != PARAM_REG)
        return ERROR;
    index = get_value_from_param(memory, FSRT_PARAM(param),
    process->registers, &i) % IDX_MOD;
    num_reg = get_value_from_param(memory, SECO_PARAM(param),
    process->registers, &i);
    if (num_reg == 0)
        return ERROR;
    num_reg -= 1;
    index = (index + process->PC) % MEM_SIZE;
    process->registers[num_reg] = get_value_from_dir(memory, &index);
    reset_process(process, i);
    return SUCESS;
}
