##
## EPITECH PROJECT, 2018
## MUL runner
## File description:
## Makefile
##

NAME	=	104intersection

SRC		=	gaetan.c		\
			equation.c		\
			error.c			\
			print.c			\
			formule.c

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
