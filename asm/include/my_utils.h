/*
** EPITECH PROJECT, 2023
** my_utils.h
** File description:
** header
*/

#ifndef MY_UTILS
    #define MY_UTILS

    #include <stddef.h>

    #include "my_def.h"

size_t str_len(const char * str);
size_t pad_len(size_t len);
size_t nbr_len(long int nbr);

int str_cmp(const char * s1, const char * s2);

char * str_cpy(char * dst, const char * src);
char * str_cat(char * dst, const char * src);
char * str_chr(const char * str, char chr);

void * mem_cpy(void * dst, const void * src, size_t n);
void * mem_set(void * dst, int c, size_t n);

char * my_itoa(long int nbr);
char * my_ftoa(double nbr, int precision);

long int my_atoi(const char * str);

double power(int x, int p);

void * vfree(size_t n, ...);
void * obj_vfree(size_t n, ...);
void * try_free(void * ptr);

list_str_t * split(str_t * str, const char * sep, int clean, int keepquote);
list_str_t * filter(list_str_t * list);

size_t str_count_char(const char * str, char c);

#endif /* MY_UTILS */
