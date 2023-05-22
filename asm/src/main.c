/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** main
*/

#include "asm.h"

// static header_t * init_header(void)
// {
//     header_t * header = malloc(sizeof(header_t));
//     int magic = big_endian(COREWAR_EXEC_MAGIC);
//     int prog_size = big_endian(22);
//     char prog_name[] = "Abel";
//     char comment[] = "L'amer noir.";

//     mem_set(header->prog_name, 0, sizeof(header->prog_name));
//     mem_set(header->comment, 0, sizeof(header->comment));

//     header->magic = magic;
//     mem_cpy(header->prog_name, prog_name, sizeof(prog_name));
//     header->prog_size = prog_size;
//     mem_cpy(header->comment, comment, sizeof(comment));

//     return header;
// }

// static void write_header(header_t * h)
// {
//     FILE * file = fopen("test.cor", "w");

//     fwrite(h, sizeof(header_t), 1, file);

//     fclose(file);
// }
// header_t * header = init_header();

// write_header(header);
// free(header);

int main(UNUSED int ac, char ** av)
{
    parse_asm((av[1]) ? av[1] : "abel.s");

    return 0;
}
