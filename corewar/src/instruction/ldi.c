/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** ldi
*/

#include "corewar_macros.h"
#include "macros.h"
#include "corewar_type.h"
#include "corewar_proto.h"

int load_index(octet_t memory[MEM_SIZE], process_t *process)
{
    octet_t parameters = PARAMETERS(memory, process->PC);
    int i = 2;
    int value = 0;

    if (process->wait < 25)
        return SUCESS;
    if (THRD_PARAM(parameters) != PARAM_REG)
        return ERROR;
    value = get_value_from_param_ind
    (memory, FSRT_PARAM(parameters), process->registers, &i);
    value = ((process->PC + value) % IDX_MOD) % MEM_SIZE;
    value = GET_MEM_IND(memory, &value);
    value += get_value_from_param_ind
    (memory, SECO_PARAM(parameters), process->registers, &i);
    value = ((process->PC + value) % IDX_MOD) % MEM_SIZE;
    value = GET_MEM_DIR(memory, &value);
    set_register(process, GET_OCTET(memory, process->PC, i), value, true);
    reset_process(process, i + 1);
    return SUCESS;
}
