/*
** EPITECH PROJECT, 2023
** mem_cpy.c
** File description:
** utils
*/

#include <unistd.h>

#include "my_print.h"
#include "my_utils.h"

void write_fd(int fd, const char * str)
{
    size_t len = str_len(str);

    write(fd, str, len);
}

void write_error(const char * str)
{
    write_fd(2, "\033[1;31mERROR\033[1;0m: ");
    write_fd(2, str);
}

void write_line_error(const char * str, int line)
{
    char * nbr = my_itoa(line);

    write_fd(2, "\033[1;31mERROR\033[1;0m: ");
    write_fd(2, "\033[1;34mline ");
    write_fd(2, nbr);
    write_fd(2, "\033[1;0m: ");
    write_fd(2, str);

    free(nbr);
}
