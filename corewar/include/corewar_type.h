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
typedef short indirect_t;
typedef int direct_t;
typedef indirect_t indexe_t;

typedef struct process {
    char *name;
    int PC;
    int wait;
    int time_left;
    int size;
    direct_t registers[REG_NUMBER];
    int fd;
    int carry;
} process_t;

typedef struct corewar {
    process_t *processes;
    int nb_processes;
    int nb_original_prog;
    char mem[MEM_SIZE];
    char **filenames;
} corewar_t;

#endif /* !corewar_type_H_ */
