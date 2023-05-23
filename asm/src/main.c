/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include "asm.h"

static void free_champ(champ_t * champ)
{
    free(champ->hdr);
    destroy(champ->cmd);
    free(champ);
}

static void display_help(void)
{
    print("\nUsage:\n\t./asm file_name[.s]\n\n");
}

int main(UNUSED int ac, const char * const * av)
{
    champ_t * champ = NULL;

    if (ac != 2) {
        display_help();
        return ERROR;
    } else if (str_cmp(av[1], "-h") == 0) {
        display_help();
        return SUCCESS;
    }
    champ = parse_asm(av[1]);
    if (champ == NULL)
        return ERROR;
    if (write_champ(av[1], champ) == ERROR) {
        free_champ(champ);
        return ERROR;
    }
    dprint(2, "%sdone.%s\n", GREEN, RESET);
    return SUCCESS;
}
