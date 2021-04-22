##
## EPITECH PROJECT, 2018
##  | Makefile
## File description:
## Makefile to make a lib
##

NAME	=	libmy.a

SRC		=	my_getnbr.c		\
			my_putchar.c	\
			my_putstr.c		\
			my_put_nbr.c	\

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

clean :
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
