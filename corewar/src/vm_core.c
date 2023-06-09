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

int vm_core(int ac, char const *av[])
{
    corewar_t *core = corewar_store();
    core->nb_prog = 0;
    core->progs = 0;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return helper();
    else if (ac < 3)
        return EXIT_ERROR;
    if (init_all(core, av) == ERROR)
        return EXIT_ERROR;
    core->cycle_delta = 1;
    core->nb_live_called = 0;
    run_corewar(core, is_dash_dump_on(av));
    free(core->all_names);
    free(core->progs);
    return SUCESS;
}
