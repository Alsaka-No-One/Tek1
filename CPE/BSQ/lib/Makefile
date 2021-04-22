##
## EPITECH PROJECT, 2018
## Bootstrap printf | Makefile
## File description:
## Makefile to make a lib
##

NAME		=	libmy.a

SRC		=	my_putchar.c		\
			my_put_nbr.c		\
			my_putstr.c		\
			my_getnbr.c		\
			my_printf.c		\
			convert_hexa_low.c	\
			convert_hexa_maj.c	\
			convert_to_octal.c	\
			convert_to_octal2.c	\
			convert_binary.c	\
			my_revstr.c		\
			my_strlen.c		\
			string_nonprintable.c	\
			my_put_nbr_long.c

OBJ		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
			ar rc $(NAME) $(OBJ)

clean :
			rm -rf $(OBJ)

fclean:			clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
