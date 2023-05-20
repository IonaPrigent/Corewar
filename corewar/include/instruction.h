/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** instruction
*/

#include "core_type.h"

#ifndef INSTRUCTION_H_
    #define INSTRUCTION_H_

typedef int instruction_t(char memory[MEM_SIZE], process_t *process);

instruction_t load;
instruction_t store;
instruction_t store_indexe;

#endif /* !INSTRUCTION_H_ */
