##
## EPITECH PROJECT, 2018
## MAths | torus
## File description:
## Makefile
##

NAME	=	105torus

SRC		=	main.c				\
			src/bissection.c	\
			src/help.c			\
			src/newton.c		\
			src/secant.c		\
			src/solvefx.c		\

OBJ		=	$(SRC:.c=.o)

CCO		=	gcc -o

CFLAGS	+= -I./include/

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CCO) $(NAME) -g3 -lm $(OBJ)

clean :
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
