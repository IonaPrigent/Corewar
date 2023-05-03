##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## Makefile
##

CFLAGS += -Wall -Wextra -pedantic -std=c99

CPPFLAGS	+=	-I./include

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
	$(RM) vgcore*

debug: CFLAGS += -g
debug: $(NAME)

re:	fclean all

.PHONY: all clean fclean re debug
