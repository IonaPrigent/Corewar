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

void read_mem(void *buffer, char mem[MEM_SIZE], int index, size_t size)
{
    char *ptr = (char *)buffer;

    index += MEM_SIZE;
    for (size_t j = 0; j < size; ++j) {
        ptr[j] = mem[(index - j) % MEM_SIZE];
    }
}

int load_index(octet_t memory[MEM_SIZE], process_t *process)
{
    octet_t parameters = PARAMETERS(memory, process->PC);
    int i = process->PC + 2;
    int value = 0;

    if (process->wait < op_tab[LDI].nbr_cycles)
        return SUCESS;
    if (THRD_PARAM(parameters) != PARAM_REG)
        return ERROR;
    value = get_value_from_param_ind
    (memory, FSRT_PARAM(parameters), process->registers, &i);
    value = (process->PC + value % IDX_MOD) % MEM_SIZE;
    read_mem(&value, memory, value, IND_SIZE);
    value += get_value_from_param_ind
    (memory, SECO_PARAM(parameters), process->registers, &i);
    value = (process->PC + value % IDX_MOD) % MEM_SIZE;
    read_mem(&value, memory, value, REG_SIZE);
    set_register(process, GET_OCTET(memory, i) - 1, value, true);
    reset_process(process, i + 1);
    return SUCESS;
}
