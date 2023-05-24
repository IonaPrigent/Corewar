/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** instruction
*/

#include "corewar_type.h"
#include "op.h"

#ifndef INSTRUCTION_H_
    #define INSTRUCTION_H_

typedef int instruction_t(char memory[MEM_SIZE], process_t *process);

instruction_t load;
instruction_t store;
instruction_t store_index;
instruction_t add;
instruction_t affich;
instruction_t and_fct;
instruction_t fork_fct;
instruction_t load_index;
instruction_t lfork;
instruction_t live;
instruction_t long_load;
instruction_t long_load_index;
instruction_t or_fct;
instruction_t sub;
instruction_t xor_fct;
instruction_t zjump;

static instruction_t *const all_instruction[] = {
    live,
    load,
    store,
    add,
    sub,
    and_fct,
    or_fct,
    xor_fct,
    zjump,
    load_index,
    store_index,
    fork_fct,
    long_load,
    long_load_index,
    lfork,
    affich
};

#define NB_INSTRUCTION sizeof(all_instruction) / sizeof(instruction_t *)
#define IS_INSTRUCTION(nb) (0 < nb && (unsigned int)nb < (int)NB_INSTRUCTION + 1)

#endif /* !INSTRUCTION_H_ */
