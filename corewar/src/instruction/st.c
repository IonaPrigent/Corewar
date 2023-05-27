/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** st
*/

#include "corewar_proto.h"
#include "corewar_macros.h"
#include "corewar_type.h"
#include "macros.h"

static int store_in_reg(char mem[MEM_SIZE], process_t *process,
int reg_id, int i)
{
    int id_dest = GET_OCTET(mem, i);

    if (!IS_REG(id_dest)) {
        return ERROR;
    }
    --id_dest;
    process->registers[id_dest] = process->registers[reg_id];
    ++i;
    reset_process(process, i);
    return SUCESS;
}

static int store_in_mem(char mem[MEM_SIZE], process_t *process,
int reg_id, int i)
{
    int index = (short)get_value_from_param_ind(mem, PARAM_IND,
    process->registers, &i);

    index = (index % IDX_MOD + process->PC) % MEM_SIZE;
    place_memory(mem, process->registers[reg_id], index);
    reset_process(process, i);
    return SUCESS;
}

int store(octet_t memory[MEM_SIZE], process_t *process)
{
    octet_t param = PARAMETERS(memory, process->PC);
    int i = process->PC + 2;
    int reg_id;

    if (process->wait < op_tab[ST].nbr_cycles)
        return SUCESS;
    if (FSRT_PARAM(param) != PARAM_REG)
        return ERROR;

    reg_id = GET_OCTET(memory, i);
    if (!IS_REG(reg_id))
        return ERROR;
    i += REG_LEN;
    if (SECO_PARAM(param) == PARAM_REG) {
        return store_in_reg(memory, process, reg_id - 1, i);
    }
    return store_in_mem(memory, process, reg_id - 1, i);
}
