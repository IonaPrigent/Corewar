/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** asm
*/

#ifndef ASM_H_
    #define ASM_H_
    #define ERROR (84)
    #define SUCCESS (0)

    #include <stdbool.h>

char *open_file(char const *file_name);
void quotes_conditions(char *buf);
int my_strcmp(char const *s1, char const *s2);

#endif /* !ASM_H_ */
