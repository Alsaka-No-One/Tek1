##
## EPITECH PROJECT, 2018
## MUL runner
## File description:
## Makefile
##

NAME	=	sort_words

SRC		=	main.c		\
			src/words.c	\
			src/sort.c	\
			src/error.c

OBJ		=	$(SRC:.c=.o)

CCO		=	gcc -o

LIB		=	-L./lib -lmy

CFLAGS	+= -I./include/

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
