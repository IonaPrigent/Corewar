/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** open_file
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *open_file(char const *file_name)
{
    int size = 0;
    struct stat statis;
    int fd = 0;
    char *buffer = NULL;

    if (stat(file_name, &statis) < 0)
        return NULL;
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        return NULL;
    size = statis.st_size;
    buffer = malloc((sizeof(char)) * (size + 1));
    if (buffer == NULL)
        return NULL;
    if (read(fd, buffer, size) < 1)
        return NULL;
    buffer[size] = '\0';
    return buffer;
}
