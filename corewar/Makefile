##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## Makefile
##

CFLAGS += -Wall -Wextra

CPPFLAGS	+=	-I./include

LDFLAGS	+= -L./lib/my -lmy

BASE_SRC	=

SRC	=	$(BASE_SRC)	\
		src/main.c

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
