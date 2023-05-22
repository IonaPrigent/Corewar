/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** aff
*/

#include "corewar_macros.h"
#include "macros.h"
#include "corewar_type.h"
#include "corewar_proto.h"

int load_index(octet_t memory[MEM_SIZE], process_t *process)
{
    octet_t reg_id = GET_OCTET(memory, process->PC, 1);

    if (process->wait < 25)
        return SUCESS;
    reset_process(process->PC, 2);
    return SUCESS;
}
