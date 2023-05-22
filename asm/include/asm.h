/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** op
*/

#ifndef MY_ASM
    #define MY_ASM

    #include <stdlib.h>
    #include <stdio.h>

    #include "my_lib.h"
    #include "op.h"

    #define SUCCESS 0
    #define ERROR 84

/**
 * @brief convert a little endian int to big endian (reverse bytes).
*/
int big_endian(int nbr);

list_str_t * parse_asm(const char * filename);

// list_str_t * special_split(str_t * str, const char * sep);

#endif /* MY_ASM */
