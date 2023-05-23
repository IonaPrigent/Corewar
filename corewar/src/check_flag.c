/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** check_flag
*/

#include <stddef.h>
#include "macros.h"
#include "my.h"

int is_dash_dump_on(char const *av[])
{
    int nbr_cycle = 0;

    if (my_strcmp(av[2], "-dump") == 0) {
        nbr_cycle = my_getnbr(av[3]);
        return nbr_cycle;
    }
    return -1;
}

char *is_dash_adress_on(char const *av[])
{
    char *adress = NULL;

    for (int i = 0; av[i]; i++) {
        if (my_strcmp(av[i], "-a") == 0) {
            my_strcpy(adress, av[i + 1]);
            return adress;
        }
    }
    return NULL;
}
