/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include "op.h"
#include "asm.h"
#include <unistd.h>

int main(int ac, char **av)
{
    char *buffer = NULL;
    char name[PROG_NAME_LENGTH] = "hey";
    char comment[COMMENT_LENGTH] = "hello";
    header_t header;
    header.magic = 0xea83f3;
    header.prog_size = 22;

    for (int i = 0; i < PROG_NAME_LENGTH; i++)
        header.prog_name[i] = 0x0;
    for (int i = 0; i < COMMENT_LENGTH; i++)
        header.comment[i] = 0x0;

    for (int i = 0; name[i] != '\0'; i++)
        header.prog_name[i] = name[i];
    for (int i = 0; comment[i] != '\0'; i++)
        header.comment[i] = comment[i];
    if (ac == 1) {
        buffer = open_file(av[1]);
    }
    if (ac > 2 || ac < 2)
        return ERROR;
    write(1, &header, sizeof(header_t));
    return 0;
}
