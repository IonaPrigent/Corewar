/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** vm_core_file
*/

#include "core_type.h"
#include "macros.h"
#include "corewar_proto.h"

int vm_core(void)
{
    octet_t arena[SIZE_ARENA];
    display_memory(arena);
    return SUCESS;
}