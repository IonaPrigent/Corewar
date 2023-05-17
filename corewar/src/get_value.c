/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_value
*/

#include "core_type.h"
#include "op.h"

int get_value_from_indirect(octet_t const *memory)
{
    int value = 0;

    for (int i = 0; i < T_IND; ++i) {
        value <<= 8;
        value += memory[i];
    }
    return value;
}

int get_value_from_direct(octet_t const *memory)
{
    int value = 0;

    for (int i = 0; i < T_DIR; ++i) {
        value <<= 8;
        value += memory[i];
    }
    return value;
}