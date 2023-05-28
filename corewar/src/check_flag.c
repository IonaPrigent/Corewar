/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** check_flag
*/

#include <stddef.h>
#include <stdlib.h>
#include "corewar_type.h"
#include "macros.h"
#include "my.h"

long is_dash_dump_on(char const *av[])
{
    int nbr_cycle = 0;

    if (my_strcmp(av[1], "-dump") == 0) {
        nbr_cycle = my_getnbr(av[2]);
        return nbr_cycle;
    }
    return -1;
}

void is_dash_adress_on(corewar_t *core, char const *av[])
{
    int a = 0;
    core->adresses = malloc(sizeof(char *) * core->nb_prog);

    for (int i = 0; av[i]; i++) {
        if (my_strcmp(av[i], "-a") == 0 || (a &&
        my_strcmp(av[i + 1] + (my_strlen(av[i + 1]) - 4), ".cor") == 0)) {
            my_strcpy(core->adresses[a], av[i + 1]);
            a++;
        }
    }
}
