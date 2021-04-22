##
## EPITECH PROJECT, 2018
## C Pool Bistro-matic | Makefile
## File description:
## Makefile
##

RM 		=	rm -rf 

CC		=	gcc

NAME		=	calc

MAKE		=	make

CFLAGS		=	-Wall -Wextra

CPPFLAGS	=	-I ./include -I ./lib/mylibc/include

LDFLAGS 	=	-L./lib/mylibc -lmy

SRCFILES	=	main.c				\
			calc.c				\
			modul/infin_add.c		\
			modul/infin_div.c		\
			modul/infin_addnathan.c		\
			modul/infin_mult.c		\
			modul/main.c			\
			itwork.c			\
			modul/my_strlen.c

SRC     	=	$(addprefix ./src/, $(SRCFILES))

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

.PHONY:			all clean fclean re
