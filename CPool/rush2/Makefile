##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## rush
##

SRC	=	step01.c \
		lib/my/libmy.a

OBJ	=	$(SRC:.c=.o)

NAME	=	step01

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

fclean:
	rm -f $(NAME)

re:	fclean all

clean:
	rm -f *~ | rm -f '#*#'
