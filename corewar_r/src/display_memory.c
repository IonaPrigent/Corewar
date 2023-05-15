/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** display_memory_file
*/

#include <unistd.h>
#include "core_type.h"
#include "macros.h"
#include "my.h"

void display_memory(octet_t memory[])
{
    for (int i = 0; i < SIZE_ARENA; i += 0x20) {
        my_puthex(i);
        write(1, "\n", 1);
    }
}
