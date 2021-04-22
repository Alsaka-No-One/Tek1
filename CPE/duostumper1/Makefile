##
## EPITECH PROJECT, 2018
## 
## File description:
## Makefile
##

NAME		=	fractals

SRC		=	src/compteur.c		\
			src/error_handling.c	\
			fractal.c		\
			src/draw_fractal.c	\
			main.c	

OBJ		=	$(SRC:.c=.o)

CCO		=	gcc -o

LIB		=	-L./lib -lmy

CFLAGS	+= -I./include/ -I./lib./include/

CSFML	=	-l csfml-graphics -l csfml-window -l csfml-system

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C ./lib
			$(CCO) $(NAME) -g3 $(OBJ) $(LIB)

clean :
			rm -rf $(OBJ)
			make clean -C ./lib

fclean:		clean
			rm -rf $(NAME)
			make fclean -C ./lib

re:			fclean all

.PHONY:		all clean fclean re
