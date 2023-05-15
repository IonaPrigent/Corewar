/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** core_type
*/

#include "op.h"

#ifndef CORE_TYPE_H_
    #define CORE_TYPE_H_

typedef char octet_t;

typedef octet_t register_t;
typedef short indirect_t;
typedef int direct_t;
typedef indirect_t indexe_t;

typedef struct process {
    char *name;
    int index;
    int registers[REG_NUMBER];
} process_t;

#endif /* !CORE_TYPE_H_ */
