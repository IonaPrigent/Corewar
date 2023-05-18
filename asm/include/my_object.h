/*
** EPITECH PROJECT, 2023
** my_object.h
** File description:
** header
*/

#ifndef MY_OBJECT
    #define MY_OBJECT

    #include <stdlib.h>
    #include <stdarg.h>

    #include "my_string.h"
    #include "my_vector.h"
    #include "my_list.h"
    #include "my_dict.h"

enum OBJECT {
    STR,
    VEC,
    LIST,
    DICT,
};

/**
 * @brief create an object. every object has a different type.
 *
 * @param type [ STR , VEC , LIST , DICT ]
 *
 * @param STR  [data]
 * @param VECT [data size, len]
 * @param LIST [len]
 * @param DICT [nb buckets]
 *
 * @return a new object
*/
void * create(int type, ...);

/**
 * @brief append some data to an object. the data depends on the object.
 *
 * @param ptr object pointer
 *
 * @param VECT [data]
 * @param LIST [data]
 * @param DICT [key, value]
 *
 * @return the object
*/
void * append(void * ptr, ...);

/**
 * @brief insert some data to an object. the data depends on the object.
 *
 * @param ptr object pointer
 *
 * @param VECT [index, data]
 * @param LIST [index, data]
 * @param DICT [key, value]
 *
 * @return the object
*/
void * insert(void * ptr, ...);

/**
 * @brief update some data of an object.
 *
 * @param obj object
 *
 * @param VECT [index, data]
 * @param LIST [index, data]
 * @param DICT [key, value]
 *
 * @return the object
*/
void * update(void * ptr, ...);

/**
 * @brief delete some data of an object.
 *
 * @param ptr object
 *
 * @param obj VECT [index]
 * @param obj LIST [index]
 * @param obj DICT [key]
 *
 * @return the object
*/
void * delete(void * obj, ...);

/**
 * @brief free an object according to it's type.
 *
 * @param obj oject
*/
void destroy(void * obj);

/**
 * @brief linked to the macro AUTOFREE.
 *
 * @param ptr object pointer
*/
void auto_free(void * ptr);

/**
 * @brief duplicate an object.
 *
 * @param obj object to duplicate
 *
 * @return a copy of obj
*/
void * duplic(void * obj);

/**
 * @brief convert an object to a string.
 *
 * @param obj obj to convert
*/
str_t * string(void * obj, str_t ** buff);

/**
 * @brief set the type of an object
 *
 * @param obj target object
 * @param type type of the object
*/
void set_obj_type(void * obj, int type);

/**
 * @brief get the type of an object
 *
 * @param obj target object
 *
 * @return type of the object as an integer
*/
int get_obj_type(void * obj);

/**
 * @brief allocate an object and his hidden part (type).
 *
 * @param type type of the object
 * @param size size of the structure of the object
 *
 * @return the allocated object
*/
void * alloc_obj(int type, size_t size);

#endif /* MY_OBJECT */
