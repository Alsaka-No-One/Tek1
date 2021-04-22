##
## EPITECH PROJECT, 2018
##  | Makefile
## File description:
## Makefile to make a lib
##

NAME		=	libmy.a

SRC			=	my_putchar.c		\
				my_strlen.c		\
				my_strcpy.c		\
				my_putstr.c		\
				my_put_nbr.c		\
				my_revstr.c		\

OBJ			=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
				ar rc $(NAME) $(OBJ)

clean :
				rm -rf $(OBJ)

fclean:			clean
				rm -rf $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
