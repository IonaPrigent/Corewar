/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** set_register
*/

#include "corewar_macros.h"
#include "corewar_type.h"
#include <stdbool.h>

void set_register(process_t *process, int reg_id, int value, bool mod_carry)
{
    process->registers[reg_id] = value;
    if (mod_carry) {
        process->carry = (value == 0);
    }
}
