##
## EPITECH PROJECT, 2018
## 
## File description:
## Makefile
##

NAME		=	palindrome

SRC		=	main.c		\

OBJ		=	$(SRC:.c=.o)

CCO		=	gcc -o

LIB		=	-L./lib -lmy

CFLAGS		+= -I./include/

CSFML		=	-l csfml-graphics -l csfml-window -l csfml-system

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CCO) $(NAME) -g3 $(OBJ)

clean :
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
