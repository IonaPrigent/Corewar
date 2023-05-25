/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** my_putnbr
*/

#include <unistd.h>

void my_putnbr(unsigned int nb)
{
    char c = 0;
    int value = nb % 10;

    if (nb > 9) {
        my_putnbr(nb / 10);
    }
    c = value + '0';
    write(1, &c, 1);
}
