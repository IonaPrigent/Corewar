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

/*
*   registers
*/
void set_register(process_t *process, int reg_id, int value, bool mod_carry);

/*
*   memory management
*/
void place_memory(char memory[MEM_SIZE], int value, int idx);
void display_memory(octet_t memory[]);

/*
*   initialisation
*/
int init_all(corewar_t *core, int ac, char const *av[]);
int get_prog_name(int fd, header_t *program);
int check_magic_number(int fd, header_t *program);
int get_prog_size(int fd, header_t *program);
int get_program(int fd, header_t *program);

corewar_t *corewar_store(void);

void reset_process(process_t *process, int i);

#endif /* !COREWAR_PROTO_H_ */
