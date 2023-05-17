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

typedef octet_t reg_t;
typedef short indirect_t;
typedef int direct_t;
typedef indirect_t indexe_t;

typedef struct process {
    char *name;
    int PC;
    int wait;
    int ID;
    int registers[REG_NUMBER];
} process_t;

    #define PARAM_REG 0b01
    #define PARAM_DIR 0b10
    #define PARAM_IND 0b11

    #define PARAM_MASK 0b11
    #define FSRT_PARAM(x) ((x >> 6) & PARAM_MASK)
    #define SECO_PARAM(x) ((x >> 4) & PARAM_MASK)
    #define THRD_PARAM(x) ((x >> 2) & PARAM_MASK)
    #define FRTH_PARAM(x) (x & PARAM_MASK)

enum INSTRUCTIONS_NAME {
    LIVE,
    LD, 
    ST,
    ADD,
    SUB,
    AND,
    OR,
    XOR,
    ZJUMP,
    LDI,
    STI,
    FORK,
    LLD,
    LLDI,
    LFORK,
    AFF
};

#endif /* !CORE_TYPE_H_ */
