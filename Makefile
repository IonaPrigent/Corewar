##
## EPITECH PROJECT, 2023
## main
## File description:
## makefile
##

all:
	make -C asm
	make -C corewar

clean:
	make clean -C asm
	make clean -C corewar

fclean:
	make fclean -C asm
	make fclean -C corewar

re:
	make re -C asm
	make re -C corewar

debug:
	make debug -C asm
	make debug -C corewar

.PHONY: all clean fclean re unit_tests tests_run debug
