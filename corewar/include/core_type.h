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
    int time_left;
    int registers[REG_NUMBER];
} process_t;

    #define PARAM_REG 0b01
    #define PARAM_DIR 0b10
    #define PARAM_IND 0b11

    #define PARAM_MASK 0b11
    #define GET_OCTET(mem, PC, i) (mem[(PC + i) % MEM_SIZE])
    #define PARAMETERS(mem, PC) (GET_OCTET(mem, PC, 1))
    #define FSRT_PARAM(param) ((param >> 6) & PARAM_MASK)
    #define SECO_PARAM(param) ((param >> 4) & PARAM_MASK)
    #define THRD_PARAM(param) ((param >> 2) & PARAM_MASK)
    #define FRTH_PARAM(param) (param & PARAM_MASK)
    #define IS_REG(reg) (0 < reg && reg <= REG_NUMBER)

    #define REPLACE_PC(PC, i) ((PC + i) % MEM_SIZE)

    #define REG_LEN 1
    #define IND_LEN IND_SIZE
    #define DIR_LEN DIR_SIZE

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
