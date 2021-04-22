##
## EPITECH PROJECT, 2018
## B-CPE-100 | C Pool Rush - Rush #2 | Makefile
## File description:
## Makefile for running the whole program
##

RM 		=	rm -rf 

CC		=	gcc

COMP		=	ar rc

MAKE		=	make

NAME		=	libmy.a

CPPFLAGS	=	-I ./include

SRCFILES	=	my_putchar.c			\
			my_putstr.c			\
			my_strlen.c			\
			my_put_nbr.c			\
			my_getnbr.c

SRC		=	$(addprefix ./src/, $(SRCFILES))

OBJ 		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):	 	$(OBJ)
			$(COMP) -o $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
