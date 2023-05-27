/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** and
*/

#include <stdbool.h>
#include "corewar_macros.h"
#include "corewar_type.h"
#include "corewar_proto.h"
#include "macros.h"

int and_fct(octet_t memory[MEM_SIZE], process_t *process)
{
    int i = process->PC + 2;
    octet_t parameters = PARAMETERS(memory, process->PC);
    int reg_id1 = 0;
    int reg_id2 = 0;
    int reg_id3 = 0;
    int result = 0;

    if (process->wait < op_tab[ADD].nbr_cycles)
        return SUCESS;
    if (check_all_param_reg(parameters))
        return ERROR;
    reg_id1 = GET_OCTET(memory, i);
    reg_id2 = GET_OCTET(memory, i + 1);
    reg_id3 = GET_OCTET(memory, i + 2);
    if (!IS_REG(reg_id1) || !IS_REG(reg_id2) || !IS_REG(reg_id3))
        return ERROR;
    result = process->registers[reg_id1 - 1] & process->registers[reg_id2 - 1];
    set_register(process, reg_id3 - 1, result, true);
    reset_process(process, i + 3);
    return SUCESS;
}
