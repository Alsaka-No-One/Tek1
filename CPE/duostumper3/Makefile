##
## EPITECH PROJECT, 2018
## 
## File description:
## Makefile
##

NAME	=	crocus

SRC		=	src/error_gestion.c		\
			src/fill_tab.c			\
			src/write_number.c		\
			writ.c				\
			src/find_symbol.c		\
			crocus.c			\
			main.c

OBJ		=	$(SRC:.c=.o)

CCO		=	gcc -o

LIB		=	-L./lib -lmy

CFLAGS	+= -I./include/ -g3

CSFML	=	-l csfml-graphics -l csfml-window -l csfml-system

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CCO) $(NAME) $(OBJ)

clean :
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
