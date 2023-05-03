##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## Makefile
##

CFLAGS	+=	-Wall -Wextra

CPPFLAGS	+=	-I../../include

SRC 	=	my_strcmp.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME)	:	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
