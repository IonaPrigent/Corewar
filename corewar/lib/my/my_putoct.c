/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** my_putoct
*/

#include <unistd.h>

void my_putoct(unsigned int nb)
{
    char c = 0;

    if (nb > 7) {
        my_putoct(nb / 8);
    }
    c = nb % 8 + 48;
    write(1, &c, 1);
}
