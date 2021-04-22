##
## EPITECH PROJECT, 2018
## PSU my_ls
## File description:
## Makefile
##

NAME	=	my_ls

SRC		=	main.c				\
			src/check_arg.c		\
			src/ls_d.c			\
			src/ls_l.c			\
			src/ls_l_bis.c		\
			src/ls_recurs.c		\

OBJ		=	$(SRC:.c=.o)

CCO		=	gcc -o

LIB		=	-L./lib -lmy

CFLAGS	+= -I./include/ -Wall -Wextra -Werror

CSFML	=	-l csfml-graphics -l csfml-window -l csfml-system

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C ./lib
			$(CCO) $(NAME) -g3 $(OBJ) $(LIB) $(CFLAGS)

clean :
			rm -rf $(OBJ)
			make clean -C ./lib

fclean:		clean
			rm -rf $(NAME)
			make fclean -C ./lib

re:			fclean all

.PHONY:		all clean fclean re
