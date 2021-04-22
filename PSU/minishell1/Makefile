##
## EPITECH PROJECT, 2018
## 
## File description:
## Makefile
##

NAME	=	mysh

SRC		=	src/str_comp.c			\
			src/env.c				\
			src/copy_env.c			\
			src/separate_to_arg.c	\
			src/exit.c				\
			main.c

OBJ		=	$(SRC:.c=.o)

CCO		=	gcc -o

LIB		=	-L./lib -lmy

CFLAGS	+= -I./include/ -I./lib/include/ -Wall -Wextra -Werror -g

CSFML	=	-l csfml-graphics -l csfml-window -l csfml-system

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C ./lib
			$(CCO) $(NAME) $(OBJ) $(LIB)

clean :
			rm -rf $(OBJ)
			make clean -C ./lib

fclean:		clean
			rm -rf $(NAME)
			make fclean -C ./lib

re:			fclean all

.PHONY:		all clean fclean re
