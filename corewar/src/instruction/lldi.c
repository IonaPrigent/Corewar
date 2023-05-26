/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** lldi
*/

#include "corewar_macros.h"
#include "macros.h"
#include "corewar_type.h"
#include "corewar_proto.h"

int long_load_index(octet_t memory[MEM_SIZE], process_t *process)
{
    octet_t parameters = PARAMETERS(memory, process->PC);
    int i = process->PC + 2;
    int value = 0;

    if (process->wait < op_tab[LLDI].nbr_cycles)
        return SUCESS;
    if (THRD_PARAM(parameters) != PARAM_REG)
        return ERROR;
    value = get_from_param_ind
    (memory, FSRT_PARAM(parameters), process->registers, &i);
    value = (process->PC + value) % MEM_SIZE;
    read_mem(&value, memory, value, IND_SIZE);
    value += get_from_param_ind
    (memory, SECO_PARAM(parameters), process->registers, &i);
    value = (process->PC + value) % MEM_SIZE;
    read_mem(&value, memory, value, REG_SIZE);
    set_register(process, GET_OCTET(memory, i) - 1, value, true);
    reset_process(process, i + 1);
    return SUCESS;
}
