/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** check_flag
*/

#include "macros.h"

int is_dash_dump_on(char const *av[], int ac)
{
    int nbr_cycle = 0;

    if (my_strcmp(av[2], "-dump") == 0) {
       nbr_cycle = my_getnbr(av[3]);
       return nbr_cycle;
    }
    return -1;
}