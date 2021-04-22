##
## EPITECH PROJECT, 2018
## B-CPE-100 | C Pool Rush - Rush #2 | Makefile
## File description:
## Makefile for running the whole program
##

RM 		=	rm -rf 

CC		=	gcc

AR		=	ar rc

MAKE		=	make

NAME		=	libmy.a

CPPFLAGS	+=	-I ./include

SRCFILES	=	my_putchar.c			\
			my_putstr.c			\
			my_strlen.c			\
			my_put_nbr.c

SRC		=	$(addprefix ./src/, $(SRCFILES))

OBJ 		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):	 	$(OBJ)
			$(AR) -o $(NAME) $(OBJ)

tests_run:		all
			$(MAKE) -C ./tests/

cov:
			gcovr --exclude ./tests/

clean:
			$(RM) $(OBJ)
			$(MAKE) clean -C ./tests/

fclean:			clean
			$(RM) $(NAME)
			$(MAKE) fclean -C ./tests/

re:			fclean all

.PHONY:			all clean fclean re
