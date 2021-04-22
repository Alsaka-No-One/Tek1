##
## EPITECH PROJECT, 2018
##
## File description:
## Makefile
##

NAME		=	pokemon

SRC		=	src/usefull_function.c		\
			src/imput.c			\
			src/parser.c			\
			main.c				\
			fight.c				\
			fight2.c			\
			st_to_ar.c

OBJ		=	$(SRC:.c=.o)

CCO		=	gcc -o

LIB		=	-L./lib -lmy

CFLAGS		+= -I./include/ -g3

CSFML		=	-l csfml-graphics -l csfml-window -l csfml-system

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CCO) $(NAME) $(OBJ)

clean :
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
