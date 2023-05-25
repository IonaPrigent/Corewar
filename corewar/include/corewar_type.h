/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** corewar_type
*/

#include "op.h"

#ifndef corewar_type_H_
    #define corewar_type_H_

typedef char octet_t;

typedef octet_t reg_t;
typedef char indirect_t[IND_SIZE];
typedef char direct_t[DIR_SIZE];
typedef indirect_t indexe_t;

typedef struct name {
    char name[PROG_NAME_LENGTH + 1];
    int id;
} name_t;

typedef struct process {
    int PC;
    int wait;
    int time_left;
    int registers[REG_NUMBER];
    int fd;
    int carry;
} process_t;

typedef struct corewar {
    process_t *processes;
    name_t *all_names;
    int nb_processes;
    int nb_original_prog;
    char mem[MEM_SIZE];
    char const **filenames;
    char **adresses;
} corewar_t;

#endif /* !corewar_type_H_ */
