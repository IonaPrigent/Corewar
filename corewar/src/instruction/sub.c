/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** sub
*/

#include <stdbool.h>
#include "corewar_macros.h"
#include "corewar_type.h"
#include "corewar_proto.h"
#include "macros.h"

int sub(octet_t memory[MEM_SIZE], process_t *process)
{
    int i = process->PC + 2;
    octet_t parameters = PARAMETERS(memory, process->PC);
    int reg_id1 = 0;
    int reg_id2 = 0;
    int reg_id3 = 0;
    int result = 0;

    if (process->wait < 10)
        return SUCESS;
    if (THRD_PARAM(parameters) != PARAM_REG
    || SECO_PARAM(parameters) != PARAM_REG
    || FSRT_PARAM(parameters) != PARAM_REG)
        return ERROR;
    reg_id1 = GET_OCTET(memory, process->PC, i);
    reg_id2 = GET_OCTET(memory, process->PC, i + 1);
    reg_id3 = GET_OCTET(memory, process->PC, i + 2);
    result = process->registers[reg_id1] - process->registers[reg_id2];
    set_register(process, reg_id3, result, true);
    reset_process(process, i + 3);
    return SUCESS;
}
