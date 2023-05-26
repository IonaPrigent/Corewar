/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** add
*/

#include <stdbool.h>
#include "corewar_type.h"
#include "corewar_macros.h"
#include "corewar_proto.h"
#include "macros.h"

int add(octet_t memory[MEM_SIZE], process_t *process)
{
    int i = process->PC + 2;
    octet_t parameters = PARAMETERS(memory, process->PC);
    int reg_id1 = 0;
    int reg_id2 = 0;
    int reg_id3 = 0;
    int result = 0;

    if (process->wait < op_tab[ADD].nbr_cycles)
        return SUCESS;
    if (THRD_PARAM(parameters) != PARAM_REG
    || SECO_PARAM(parameters) != PARAM_REG
    || FSRT_PARAM(parameters) != PARAM_REG)
        return ERROR;
    reg_id1 = GET_OCTET(memory, i);
    reg_id2 = GET_OCTET(memory, i + 1);
    reg_id3 = GET_OCTET(memory, i + 2);
    result = process->registers[reg_id2] + process->registers[reg_id1];
    set_register(process, reg_id3, result, true);
    reset_process(process, i + 3);
    return SUCESS;
}
