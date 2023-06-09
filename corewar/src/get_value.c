/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** get_value
*/

#include "corewar_type.h"
#include "macros.h"
#include "corewar_proto.h"
#include "corewar_macros.h"
#include "op.h"

int get_value_from_mem(octet_t const *memory, int *i, int size)
{
    int value = 0;
    int j = 0;
    octet_t *ptr = (octet_t *)&value;

    for (; j < size; j += 1) {
        ptr[j] = memory[*i % MEM_SIZE];
        *i += 1;
    }
    reverse(&value, size);
    return value;
}

void reset_process(process_t *process, int i)
{
    process->PC = i % MEM_SIZE;
    process->wait = 0;
}

int get_from_param_dir(octet_t const *memory, octet_t param,
int reg[], int *i)
{
    switch (param) {
    case PARAM_REG:
        *i += 1;
        return (IS_REG(memory[*i - 1])) ? reg[memory[*i] - 1] : ERROR;
    case PARAM_IND:
        return GET_MEM_IND(memory, i);
    case PARAM_DIR:
        return GET_MEM_DIR(memory, i);
    default:
        break;
    }
    return 0;
}

int get_from_param_ind(octet_t const *memory, octet_t param,
int reg[], int *i)
{
    switch (param) {
    case PARAM_REG:
        *i += 1;
        return (IS_REG(memory[*i - 1])) ? reg[memory[*i - 1] - 1] : ERROR;
    case PARAM_DIR:
    case PARAM_IND:
        return GET_MEM_IND(memory, i);
    default:
        break;
    }
    return 0;
}
