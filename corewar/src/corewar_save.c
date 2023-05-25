/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** corewar_save
*/

#include "corewar_type.h"

corewar_t *corewar_store(void)
{
    static corewar_t core;
    return &core;
}
