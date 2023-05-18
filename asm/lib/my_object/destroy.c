/*
** EPITECH PROJECT, 2023
** create_obj.c
** File description:
** create an object
*/

#include "my_object.h"

void str_destroy(str_t * str);
void vec_destroy(vec_t * vec);
void list_destroy(list_t * list);
void dict_destroy(dict_t * dict);

static const void * DESTROY_OBJ[] = {
    &str_destroy,
    &vec_destroy,
    &list_destroy,
    &dict_destroy,
};

void destroy(void * obj)
{
    int type = 0;
    void (* destroy_obj)(void *) = NULL;

    if (obj == NULL) {
        return;
    }

    type = get_obj_type(obj);
    destroy_obj = DESTROY_OBJ[type];
    destroy_obj(obj);
}

void auto_free(void * ptr)
{
    void * obj = * (void **) ptr;

    destroy(obj);
}
