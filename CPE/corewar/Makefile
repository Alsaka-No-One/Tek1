##
## EPITECH PROJECT, 2019
## Dante
## File description:
## Makefile
##

all:
			make -C ./asm
			make -C ./corewar

clean:
			make clean -C ./asm
			make clean -C ./corewar

fclean:		clean
			make fclean -C ./asm
			make fclean -C ./corewar

re:			fclean all

tests_run:
			make tests_run -C ./asm
			make tests_run -C ./corewar

.PHONY:		all clean fclean re
