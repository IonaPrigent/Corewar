##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CC			?=	gcc
LDFLAGS		+=	-L $(LIB_DIR)
LDLIBS		+=	-lmy
CPPFLAGS	+=	-iquote $(INC_DIR)
CFLAGS		+=	-Wall -Wextra -g3

INC_DIR		=	./include
SRC_DIR		=	./src
LIB_DIR		=	./lib

OBJECT_DIR	=	$(LIB_DIR)/my_object
VECTOR_DIR	=	$(LIB_DIR)/my_vector
STRING_DIR	=	$(LIB_DIR)/my_string
LIST_DIR	=	$(LIB_DIR)/my_list
DICT_DIR	=	$(LIB_DIR)/my_dict
PRINT_DIR	=	$(LIB_DIR)/my_print
UTILS_DIR	=	$(LIB_DIR)/my_utils
CTYPE_DIR	=	$(LIB_DIR)/my_ctype

LIB			=	$(wildcard $(OBJECT_DIR)/*.c)	\
				$(wildcard $(VECTOR_DIR)/*.c)	\
				$(wildcard $(UTILS_DIR)/*.c)	\
				$(wildcard $(LIST_DIR)/*.c)		\
				$(wildcard $(DICT_DIR)/*.c)		\
				$(wildcard $(STRING_DIR)/*.c)	\
				$(wildcard $(PRINT_DIR)/*.c)	\
				$(wildcard $(CTYPE_DIR)/*.c)	\

SRC			=	$(wildcard $(SRC_DIR)/*.c)

LIB_OBJ		=	$(LIB:.c=.o)
SRC_OBJ		=	$(SRC:.c=.o)

BIN_NAME	=	asm
LIB_NAME	=	$(LIB_DIR)/libmy.a


all: $(LIB_NAME) $(BIN_NAME)

$(BIN_NAME): $(SRC_OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS) $(CFLAGS) $(CPPFLAGS)

$(LIB_NAME): $(LIB_OBJ)
	ar rc $@ $^

clean:
	@ $(RM) $(SRC_OBJ) $(LIB_OBJ)

fclean:	clean
	@ $(RM) $(BIN_NAME) $(LIB_NAME)

re: fclean all

.PHONY:	all	clean fclean re
