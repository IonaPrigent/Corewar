/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** op
*/

#ifndef OP_H
    #define OP_H

    #define MEM_SIZE          (6 * 1024)
    #define IDX_MOD           (512) /* modulo of the index < */
    #define MAX_ARGS_NUMBER   (4)   /* this may not be changed 2^*IND_SIZE */

    #define COMMENT_CHAR            '#'
    #define LABEL_CHAR              ':'
    #define DIRECT_CHAR             '%'
    #define SEPARATOR_CHAR          ','

    #define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"

    #define NAME_CMD_STRING         ".name"
    #define COMMENT_CMD_STRING      ".comment"

/*
** regs
*/
    #define REG_NUMBER      16   /* r1 <--> rx */

/*
**
*/

typedef char args_type_t;

    #define T_REG           1       /* register */
    #define T_DIR           2       /* direct  (ld  #1,r1  put 1 into r1) */
    #define T_IND           4       /* indirect always relative
                                    ( ld 1,r1 put what's in the address (1+pc)
                                    into r1 (4 bytes )) */
    #define T_LAB           8       /* LABEL */

typedef struct op_s {
    char *mnemonique;   /* assembly name for the command */
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER]; /* arg type for the cmd (reg, dir, ind)*/
    char code;  /* int between [1-16] the command index */
    int nbr_cycles; /* nbr cycles before next move available */
    char *comment; /* command explication */
} op_t;

/*
** size (in bytes)
*/
    #define IND_SIZE        2
    #define DIR_SIZE        4
    #define REG_SIZE        DIR_SIZE    /* reg_size = 1 byte = [1-16] */
                                        /* register contain 4 byte of data */

/*
** op_tab
*/
extern op_t op_tab[];   /* operation definition (aka args + type args) */

/*
** header
*/
    #define PROG_NAME_LENGTH        128
    #define COMMENT_LENGTH          2048
    #define COREWAR_EXEC_MAGIC      0xea83f3    /* confirm redskin code */

typedef struct header_s {
    int magic;  /* redskin code confirmed */
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size; /* size of the prog, literally ! (in bytes) */
    char comment[COMMENT_LENGTH + 1];
} header_t;

/*
** live
*/
    #define CYCLE_TO_DIE    1536 /* number of cycle before beig declared dead */
    #define CYCLE_DELTA     5
    #define NBR_LIVE        40

#endif /* OP_H */

/**
 * coding byte value:
 * other:    00 // less than 4 params
 * register: 01
 * direct:   10
 * indirect: 11
 *
 * exception:
 * no coding byte because they only take one param of the same type:
 * live, zjmp, fork and lfork
*/
