/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** corewar_proto
*/

#include "core_type.h"

#ifndef COREWAR_PROTO_H_
    #define COREWAR_PROTO_H_

int is_dash_dump_on(char const *av[]);
int vm_core(int ac, char const *av[]);

/*
*   get value placed in the main memory
*/
int get_value_from_dir(octet_t const *memory, int *i);
int get_value_from_ind(octet_t const *memory, int *i);

/*
*   get parameter
*/
int get_value_from_param(octet_t const *memory, octet_t param,
int reg[], int *i);

int get_value_from_param_ind(octet_t const *memory, octet_t param,
int reg[], int *i);


void place_memory(char memory[MEM_SIZE], int value, int idx);
void display_memory(octet_t memory[]);
int init_all(process_t **all_champ, octet_t arena[MEM_SIZE],
int ac, char const *av[]);
void reset_process(process_t *process, int i);

#endif /* !COREWAR_PROTO_H_ */
