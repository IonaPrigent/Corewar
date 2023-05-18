/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/


int big_endian(int little_endian)
{
    int nbr = 0;

    nbr |= (little_endian & 0x000000FF) << 24;
    nbr |= (little_endian & 0x0000FF00) << 8;
    nbr |= (little_endian & 0x00FF0000) >> 8;
    nbr |= (little_endian & 0xFF000000) >> 24;

    return nbr;
}
