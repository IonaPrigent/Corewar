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
    #include "error.h"

    #define SUCCESS 0
    #define ERROR 84

typedef struct champ_s {
    header_t * hdr;
    vec_t * cmd;
} champ_t;

/**
 * @brief convert a little endian int to big endian (reverse bytes).
*/
int big_endian(int nbr);

champ_t * parse_asm(const char * filename);

void write_header(FILE * file, header_t * header);

#endif /* MY_ASM */
