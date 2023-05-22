/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** ld
*/

#include <stdbool.h>
#include "corewar_proto.h"
#include "corewar_macros.h"
#include "corewar_type.h"
#include "macros.h"

int load(octet_t memory[MEM_SIZE], process_t *process)
{
    int index = 0;
    int i = 2;
    int reg_id = 0;
    octet_t param = PARAMETERS(memory, process->PC);

    if (process->wait < 5)
        return SUCESS;
    if (SECO_PARAM(param) != PARAM_REG)
        return ERROR;
    index = get_value_from_param(memory, FSRT_PARAM(param),
    process->registers, &i) % IDX_MOD;
    reg_id = GET_OCTET(memory, process->PC, i);
    ++i;
    if (reg_id == 0)
        return ERROR;
    reg_id -= 1;
    index = (index + process->PC) % MEM_SIZE;
    set_register(process, reg_id, GET_MEM_DIR(memory, &index), true);
    reset_process(process, i);
    return SUCESS;
}
