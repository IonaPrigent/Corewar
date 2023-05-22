/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** corewar_proto
*/

#include "corewar_type.h"
#include "corewar_macros.h"
#include <stdbool.h>

#ifndef COREWAR_PROTO_H_
    #define COREWAR_PROTO_H_

int is_dash_dump_on(char const *av[]);
int vm_core(int ac, char const *av[]);

/*
*   get value placed in the main memory
*/
int get_value_from_mem(octet_t const *memory, int *i, int size);

    #define GET_MEM_IND(mem, index) (get_value_from_mem(mem, index, IND_SIZE))
    #define GET_MEM_DIR(mem, index) (get_value_from_mem(mem, index, DIR_SIZE))

/*
*   get parameter
*/
int get_value_from_param(octet_t const *memory, octet_t param,
int reg[], int *i);

int get_value_from_param_ind(octet_t const *memory, octet_t param,
int reg[], int *i);

void set_register(process_t *process, int reg_id, int value, bool mod_carry);
void place_memory(char memory[MEM_SIZE], int value, int idx);
void display_memory(octet_t memory[]);
int init_all(process_t **all_champ, octet_t arena[MEM_SIZE],
int ac, char const *av[]);
int get_prog_name(int fd, header_t *program);
int check_magic_number(int fd, header_t *program);
int get_prog_size(int fd, header_t *program);
int get_program(int fd, header_t *program);
void reset_process(process_t *process, int i);

#endif /* !COREWAR_PROTO_H_ */
