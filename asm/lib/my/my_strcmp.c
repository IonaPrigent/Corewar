/*
** EPITECH PROJECT, 2023
** B-PSU-100-PAR-1-2-navy-iona.prigent
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    while ((s1[i] == s2[i]) && s1[i] && s2[i]) {
        i++;
    }
    return (s1[i] - s2[i]);
}
