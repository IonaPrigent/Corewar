/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** aff
*/

#include <unistd.h>

#include "corewar_macros.h"
#include "macros.h"
#include "corewar_type.h"
#include "corewar_proto.h"

int affich(octet_t memory[MEM_SIZE], process_t *process)
{
    int param = PARAMETERS(memory, process->PC);
    char c;
    int value;
    int reg_id = GET_OCTET(memory, process->PC + 2);

    if (process->wait < op_tab[AFF].nbr_cycles)
        return SUCESS;
    if (!IS_REG(reg_id) || param != 0x40) {
        return ERROR;
    }
    --reg_id;
    value = process->registers[reg_id] % 256;
    c = value;
    write(STDOUT_FILENO, &c, 1);
    reset_process(process, 2);
    return SUCESS;
}
