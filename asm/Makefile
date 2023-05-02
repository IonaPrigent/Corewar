##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## Makefile
##

CFLAGS += -Wall -Wextra -pedantic -std=c99

BASE_SRC	=	src/open_file.c		\

CPPFLAGS	+=	-I./include

LDFLAGS	+= -L./lib/my -lmy

SRC	=	$(BASE_SRC)	\
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

debug: CFLAGS += -g
debug: $(NAME)

re:	fclean all

.PHONY: all clean fclean re debug
