/*
** EPITECH PROJECT, 2023
** my_utils.h
** File description:
** header
*/

#ifndef MY_UTILS
    #define MY_UTILS

    #include <stddef.h>

size_t str_len(char * str);
size_t pad_len(size_t len);
size_t nbr_len(long int nbr);

int str_cmp(const char * s1, const char * s2);

char * str_cpy(char * dst, const char * src);
char * str_cat(char * dst, const char * src);

void * mem_cpy(void * dst, const void * src, size_t n);
void * mem_set(void * dst, int c, size_t n);

char * my_itoa(long int nbr);
char * my_ftoa(double nbr, int precision);

double power(int x, int p);//TODO MATHS with ABS

void vfree(size_t n, ...);
void try_free(void * ptr);

#endif /* MY_UTILS */
