##
## EPITECH PROJECT, 2018
## Bootstrap printf | Makefile
## File description:
## Makefile to make a lib
##

NAME		=	libmy.a

SRC		=	src/my_putchar.c	\
			src/my_put_nbr.c	\
			src/my_putstr.c		\
			my_printf.c		\
			src/convert_hexa_low.c	\
			src/convert_hexa_Maj.c	\
			src/convert_to_octal.c	\
			src/convert_to_octal2.c	\
			src/convert_binary.c	\
			src/my_revstr.c		\
			src/my_strlen.c		\
			src/%S.c		\
			src/my_put_nbr_long.c

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
