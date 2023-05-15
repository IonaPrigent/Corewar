##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## Makefile
##

CFLAGS += -Wall -Wextra

CPPFLAGS	+=	-iquote ./include

LDFLAGS	+= -L./lib/my -lmy

BASE_SRC	=	vm_core.c			\
				display_memory.c	\

SRC_LIB		=	$(addprefix lib/my/,	\
				my_strcmp.c				\
				my_puthex.c				\
				my_putoct.c				\
				)

SRC	=	$(addprefix src/,	\
		$(BASE_SRC)			\
		main.c				\
		)					\
		$(SRC_LIB)


OBJ	=	$(SRC:.c=.o)

NAME	=	corewar

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

debug:	CFLAGS += -g3 -fsanitize=address
debug:	CC = clang
debug:	LDFLAGS += -fsanitize=address
debug:	re

re:	fclean all

.PHONY: all clean fclean re debug
