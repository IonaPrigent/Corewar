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
    write_fd(2, "\033[31mERROR\033[0m: ");
    write_fd(2, str);
    write_fd(2, "\n");
}
