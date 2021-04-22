##
## EPITECH PROJECT, 2018
## B-CPE-100 | C Pool Rush - Rush #2 | Makefile
## File description:
## Makefile for running the whole program
##

RM 	=	rm -rf 

CC	=	gcc

NAME	=	unit_tests

MAKE	=	make

CFLAGS	+=	-Wall -Wextra -I../include

LDFLAGS +=	-L../ -lmy -lcriterion

SRC	=	test_my_putchar.c		\
		test_my_putstr.c		\
		test_my_put_nbr.c		\
		test_my_strlen.c

OBJ 	=	$(SRC:.c=.o)

all:		tests_run $(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(CFLAGS) $(SRC) --coverage $(LDFLAGS)
		@./unit_tests --verbose=1

tests_run:	$(NAME)

cov:
		gcovr --exclude ./

clean:
		$(RM) $(OBJ) *.gc*

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all tests_run cov clean fclean re
