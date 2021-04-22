##
## EPITECH PROJECT, 2018
## B-CPE-101 | C Pool Rush - Rush #3 | Makefile
## File description:
## Makefile for running the whole program
##

RM 		=	rm -rf 

CC		=	gcc

NAME		=	rush3

MAKE		=	make

CFLAGS		=	-Wall -Wextra

CPPFLAGS	=	-I ./include -I ./lib/mylibc/include

LDFLAGS 	=	-L./lib/mylibc -lmy

SRCFILES	=	main.c				\
			rush3.c

SRC     	=       $(addprefix ./src/, $(SRCFILES))

OBJ 		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME): 		$(OBJ)
			$(MAKE) -C ./lib/mylibc
			$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
			$(RM) $(OBJ)
			$(MAKE) clean -C ./lib/mylibc

fclean:			clean
			$(RM) $(NAME)
			$(MAKE) fclean -C ./lib/mylibc

re:			fclean all

.PHONY:			all tests_run cov clean fclean re
