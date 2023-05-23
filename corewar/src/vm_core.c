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
#include <fcntl.h>
#include "corewar_macros.h"
#include "corewar_type.h"
#include "op.h"
#include "macros.h"
#include "corewar_proto.h"
#include "my.h"

static int helper(void)
{
    int fd = open("assets/helper", O_RDONLY);
    char c;

    if (fd == -1) {
        my_putstr("no helper found\n");
        return EXIT_ERROR;
    }
    while (read(fd, &c, 1) == 1) {
        write(STDOUT_FILENO, &c, 1);
    }
    close(fd);
    return SUCESS;
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
    corewar_t *core = corewar_store();
    core->nb_processes = 0;
    core->processes = 0;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return helper();
    else if (ac < 3)
        return EXIT_ERROR;
    if (init_all(core, ac, av) == ERROR)
        return EXIT_ERROR;
    display_memory(core->mem);
    return SUCESS;
}
