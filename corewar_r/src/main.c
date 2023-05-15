/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main file of vm
*/

#include <unistd.h>
#include "my.h"
#include "corewar_proto.h"

int helper(void)
{
    char msg[] = "USAGE\n./corewar [-dump nbr_cycle] [[-n prog_number] "\
            "[-a load_address] prog_name] ...\nDESCRIPTION\n"\
            "-dump nbr_cycle dumps the memory after the nbr_cycle execution "\
            "(if the round isn’t already over) with the following format: 32 "\
            "bytes/line\nin hexadecimal (A0BCDEFE1DD3...)\n-n prog_number"\
            " sets the next program’s number. By default, the first free "\
            "number in the parameter order\n-a load_address sets the "\
            "next program's loading address. When no address is specified, "\
            "optimize the addresses so that the processes are as far away "\
            "from each other as possible. The addresses are MEM_SIZE modulo.";

    write(1, msg, sizeof(msg) / sizeof(char));
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return helper();
    return vm_core();
}
