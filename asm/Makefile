##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## Makefile
##

CFLAGS += -Wall -Wextra -pedantic -std=c99

CPPFLAGS	+=	-I./include

LDFLAGS	=	-L./lib/my

LDLIBS	=	-lmy

BASE_SRC	=	src/open_file.c			\
				src/errors_header.c		\
				src/parsing_header.c	\

SRC	=	$(BASE_SRC)	\
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
	make clean -C ./lib/my
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ./lib/my
	rm -f $(NAME)
	$(RM) vgcore*

debug: CFLAGS += -g
debug: $(NAME)

re:	fclean all

.PHONY: all clean fclean re debug
