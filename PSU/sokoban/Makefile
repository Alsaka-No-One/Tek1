##
## EPITECH PROJECT, 2018
## PSU my_sokoban
## File description:
## Makefile
##

NAME		=	my_sokoban

SRC		=	src/display_help.c	\
			src/get_file.c		\
			src/error.c		\
			src/get_all.c		\
			src/direction.c		\
			src/direction_box.c	\
			src/victory_condition.c	\
			main.c

SRRC 		=	src/get_file.c		\
			src/test/test.c		\
			src/error.c		

OBJ		=	$(SRC:.c=.o)

OBBJ		=	$(SRRC:.c=.o)

CCO		=	gcc -o

LIB		=	-L./lib -lmy

all:			$(NAME)

$(NAME):		$(OBJ)
			make -C ./lib
			$(CCO) $(NAME) -lncurses -g3 $(OBJ) $(LIB)

clean :
			rm -rf $(OBJ)
			make clean -C ./lib

fclean:			clean
			rm -rf $(NAME)
			make fclean -C ./lib

test_run:		$(OBBJ)
			make -C ./lib
			$(CCO) test $(OBBJ) $(LIB) -lcriterion

re:			fclean all

.PHONY:			all clean fclean re
