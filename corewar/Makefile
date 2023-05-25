##
## EPITECH PROJECT, 2023
## Corewar
## File description:
## Makefile
##

CFLAGS += -Wall -Wextra -g3

CPPFLAGS	+=	-iquote ./include

LDFLAGS	+= -L./lib/my -lmy

INSTRUCTION_SRC	=	$(addprefix instruction/, \
					add.c	\
					aff.c	\
					and.c	\
					fork.c	\
					ld.c	\
					ldi.c	\
					lfork.c	\
					live.c	\
					lld.c	\
					lldi.c	\
					or.c	\
					st.c	\
					sti.c	\
					sub.c	\
					xor.c	\
					zjmp.c	\
					)

BASE_SRC	=	vm_core.c			\
				display_memory.c	\
				check_flag.c		\
				exec_instruction.c	\
				init.c				\
				get_value.c			\
				set_register.c		\
				corewar_save.c		\
				copy_prog.c			\
				reverse.c			\

SRC_LIB		=	$(addprefix lib/my/,	\
				my_strcmp.c				\
				my_puthex.c				\
				my_putoct.c				\
				my_putnbr.c				\
				my_getnbr.c				\
				my_putstr.c				\
				my_strlen.c				\
				my_strcpy.c				\
				my_strdup.c				\
				)

SRC	=	$(addprefix src/,	\
		$(BASE_SRC)			\
		$(INSTRUCTION_SRC)		\
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

redebug:	fclean debug

re:	fclean all

.PHONY: all clean fclean re debug redebug
