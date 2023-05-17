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
int get_value_from_direct(octet_t const *memory);   
int get_value_from_indirect(octet_t const *memory);
void display_memory(octet_t memory[]);
int init_all(process_t **all_champ, octet_t arena[MEM_SIZE],
int ac, char const *av[]);

#endif /* !COREWAR_PROTO_H_ */
