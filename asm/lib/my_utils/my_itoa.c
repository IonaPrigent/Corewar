/*
** EPITECH PROJECT, 2023
** mem_cpy.c
** File description:
** utils
*/

#include <stdlib.h>

#include "my_utils.h"
#include "my_def.h"

char * my_itoa(long int nbr)
{
    int len = nbr_len(nbr);
    char * str = malloc(sizeof(char) * (len + 1));
    int index = len - 1;

    str[len] = '\0';
    str[0] = '-';

    if (nbr == 0)
        str[index] = '0';

    while (nbr != 0) {
        str[index] = '0' + ABS(nbr % 10);
        nbr /= 10;
        index -= 1;
    }
    return str;
}
