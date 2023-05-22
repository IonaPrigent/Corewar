/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include "asm.h"

int main(UNUSED int ac, const char * const * av)
{
    champ_t * champ = NULL;

    if (ac != 2)
        return ERROR;
    champ = parse_asm(av[1]);
    if (champ == NULL)
        return ERROR;

    return write_header(av[1], champ->hdr);
}
