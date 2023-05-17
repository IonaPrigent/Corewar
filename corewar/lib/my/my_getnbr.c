/*
** EPITECH PROJECT, 2023
** my_getnbr.c
** File description:
** home made atoi
*/

int my_getnbr(char const *str)
{
    int stop = 0;
    int nb = 0;

    for (int i = 0; str[i] != '\0' && stop == 0; i++) {
        if (str[i] == '-')
            return -1;
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10 + (str[i] - '0');
        } else
            stop = 1;
    }
    if (nb > 2147483647)
        return -1;
    return (nb);
}
