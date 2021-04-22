##
## EPITECH PROJECT, 2018
## 
## File description:
## Makefile
##

NAME		=	tictactoe

SRC		=	main.c			\
			src/check_arg.c		\
			src/fill_data.c		\
			src/game.c		\
			src/return_free.c	\
			src/display.c		\
			src/victory.c		\
			src/check_draw.c	\
			src/check_input.c	\
			src/check_victory.c	\
			src/verif.c

OBJ		=	$(SRC:.c=.o)

CCO		=	gcc -o

LIB		=	-L./lib -lmy

CFLAGS		+= -I./include/

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CCO) $(NAME) $(OBJ)

clean :
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
