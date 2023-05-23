/*
** EPITECH PROJECT, 2023
** memory.h
** File description:
** header
*/

#ifndef MY_MEMORY
    #define MY_MEMORY

    typedef unsigned long size_t;

    #define BYTE_COPY(dstpp, srcpp, __nbytes) \
    do {   \
        size_t nbytes = __nbytes;   \
        while (nbytes > 0) {   \
            ((unsigned char *) dstpp)[0] = ((unsigned char *) srcpp)[0];    \
            dstpp += 1; \
            srcpp += 1; \
            nbytes -= 1;    \
        }   \
    } while (0);

    #define WORD_COPY(dstpp, srcpp, nbytes) \
    do {   \
        while (nbytes >= 8) {   \
            ((size_t *) dstpp)[0] = ((size_t *) srcpp)[0];    \
            dstpp += 8; \
            srcpp += 8; \
            nbytes -= 8;    \
        }   \
    } while (0);

    #define BYTE_SET(dstpp, c, __nbytes) \
    do {   \
        size_t nbytes = __nbytes;   \
        while (nbytes > 0) {   \
            ((unsigned char *) dstpp)[0] = c;    \
            dstpp += 1; \
            nbytes -= 1;    \
        }   \
    } while (0);

    #define WORD_SET(dstpp, c, nbytes) \
    do {   \
        while (nbytes >= 8) {   \
            ((size_t *) dstpp)[0] = c;    \
            dstpp += 8; \
            nbytes -= 8;    \
        }   \
    } while (0);

#endif /* MY_MEMORY */
