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
#include "core_type.h"
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

static int init_all(process_t **all_champ, octet_t arena[MEM_SIZE],
int ac, char const *av[])
{
    for (int i = 0; i < MEM_SIZE; ++i) {
        arena[i] = 0;
    }
    return SUCESS;
}

int vm_core(int ac, char const *av[])
{
    octet_t arena[MEM_SIZE];
    process_t *all_champ = NULL;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return helper();
    else if (ac < 3)
        return EXIT_ERROR;
    if (init_all(&all_champ, arena, ac, av) == ERROR)
        return EXIT_ERROR;

    display_memory(arena);
    return SUCESS;
}
