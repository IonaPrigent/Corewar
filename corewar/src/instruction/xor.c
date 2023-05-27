/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** xor
*/

#include <stdbool.h>
#include "corewar_macros.h"
#include "corewar_type.h"
#include "corewar_proto.h"
#include "macros.h"

int xor_fct(octet_t memory[MEM_SIZE], process_t *process)
{
    int i = process->PC + 2;
    octet_t parameters = PARAMETERS(memory, process->PC);
    int result_1 = 0;
    int result_2 = 0;
    int reg_id3 = 0;
    int result = 0;

    if (process->wait < op_tab[ADD].nbr_cycles)
        return SUCESS;
    if (THRD_PARAM(parameters) != PARAM_REG)
        return ERROR;
    result_1 = GET_FST_PAR_IND(memory, parameters, process->registers, &i);
    result_2 = GET_SEC_PAR_IND(memory, parameters, process->registers, &i);
    reg_id3 = GET_OCTET(memory, i);
    if (!IS_REG(reg_id3))
        return ERROR;
    result = result_1 ^ result_2;
    set_register(process, reg_id3 - 1, result, true);
    reset_process(process, i + 1);
    return SUCESS;
}
