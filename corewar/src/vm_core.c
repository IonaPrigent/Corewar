/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** vm_core_file
*/

#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "core_type.h"
#include "op.h"
#include "macros.h"
#include "corewar_proto.h"
#include "my.h"

static int helper(void)
{
    char msg[] = "USAGE\n\t./corewar [-dump nbr_cycle] [[-n prog_number] "\
            "[-a load_address] prog_name] ...\nDESCRIPTION\n\t"\
            "-dump nbr_cycle : dumps the memory after the nbr_cycle execution "\
            "(if the round isn’t already over)\n\twith the following format: 32 "\
            "bytes/line in hexadecimal (A0BCDEFE1DD3...)\n\t-n prog_number"\
            " sets the next program’s number.\n\tBy default, the first free "\
            "number in the parameter order\n\t-a load_address sets the "\
            "next program's loading address.\n\tWhen no address is specified, "\
            "optimize the addresses so\n\tthat the processes are as far away "\
            "from each other as possible. The addresses are MEM_SIZE modulo.\n";

    write(1, msg, sizeof(msg) / sizeof(char));
    return 0;
}

void read_name(int const fd, process_t *process)
{
    char c;
    int len_name = 0;

    while (read(fd, &c, 1) && c != 0) {
        ++len_name;
        process->name = realloc(process->name, len_name);
        process->name[len_name - 1] = c;
    }
    process->name = realloc(process->name, len_name);
    process->name[len_name - 1] = c;
}

int vm_core(int ac, char const *av[])
{
    octet_t arena[MEM_SIZE];

    if (ac == 1)
        return helper();
    for (int i = 0; i < MEM_SIZE; ++i) {
        arena[i] = 0;
    }
    return SUCESS;
}
