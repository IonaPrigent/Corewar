/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** my_puthex
*/

#include <unistd.h>

void my_puthex(unsigned int nb)
{
    char c = 0;
    int value = nb % 16;

    if (nb > 15) {
        my_puthex(nb / 16);
    }
    if (value < 10) {
        c = nb % 16 + '0';
        write(1, &c, 1);
    } else {
        c = value - 10 + 'A';
        write(1, &c, 1);
    }
}
