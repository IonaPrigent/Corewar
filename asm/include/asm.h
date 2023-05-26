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
    list_t * cmd;
} champ_t;

/**
 * @brief convert a little endian int to big endian (reverse bytes).
*/
int big_endian(int nbr);

list_str_t * read_content(const char * filename);

champ_t * parse_asm(const char * filename);
header_t * parse_header(list_str_t * text);
list_t * parse_command(list_str_t * text);

int valid_arg(str_t * arg, int * op_info, dict_t * label, list_t * cmd);

dict_t * get_label(list_str_t * text);

void add_coding_byte(vec_t ** byte, int op_idx);
int has_coding_byte(const char * name);

void set_label(list_t * cmd, dict_t * label);

size_t is_index(const char * str);

int write_champ(const char * filename, champ_t * champ);

#endif /* MY_ASM */
