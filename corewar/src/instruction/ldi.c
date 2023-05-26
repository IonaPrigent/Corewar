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
    int i = process->PC + 2;
    int value = 0;
    indexe_t first_sum;

    if (process->wait < op_tab[LDI].nbr_cycles)
        return SUCESS;
    if (THRD_PARAM(parameters) != PARAM_REG)
        return ERROR;
    value = get_value_from_param_ind
    (memory, FSRT_PARAM(parameters), process->registers, &i);
    dprintf(2, "first param value:%x\n", value); // satine : 300

    value = (process->PC + value % IDX_MOD) % MEM_SIZE;
    dprintf(2, "index next value:%x\n", value); // satine : 300

    value = GET_MEM_IND(memory, &value);
    dprintf(2, "value get in mem:%x\n", value); // satine : 300

    value += get_value_from_param_ind
    (memory, SECO_PARAM(parameters), process->registers, &i);
    dprintf(2, "value after adding second param :%x\n", value); // satine : 304

    value = (process->PC + value % IDX_MOD) % MEM_SIZE;
    dprintf(2, "final index :%x\n", value); // satine : 304

    value = GET_MEM_DIR(memory, &value);
    dprintf(2, "final value :%x\n", value % 256); // satine : 104

    set_register(process, GET_OCTET(memory, i), value, true);
    reset_process(process, i + 1);
    return SUCESS;
}
