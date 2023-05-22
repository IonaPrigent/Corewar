/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** display_memory_file
*/

#include <unistd.h>
#include "corewar_macros.h"
#include "corewar_type.h"
#include "macros.h"
#include "my.h"

static void display_column(int i)
{
    my_puthex(i);
    if (i == 0) {
        write(1, "    : ", 6);
        return;
    }
    if (i < 0x100) {
        write(1, "   : ", 5);
        return;
    }
    if (i < 0x1000) {
        write(1, "  : ", 4);
        return;
    }
    if (i < 0x10000) {
        write(1, " : ", 3);
        return;
    }
}

static void print_line_octet(octet_t *line)
{
    for (int i = 0; i < 0x20; ++i) {
        my_puthex(line[i] & 0xf0 >> 4);
        my_puthex(line[i] & 0x0f);
        write(1, " ", 1);
    }
}

void display_memory(octet_t memory[])
{
    for (int i = 0; i < MEM_SIZE; i += 0x20) {
        display_column(i);
        print_line_octet(memory + i);
        write(1, "\n", 1);
    }
}
