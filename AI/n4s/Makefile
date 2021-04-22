##
## EPITECH PROJECT, 2018
## Make
## File description:
## Life better
##

SRC	=	ai.c		\
		nathan.c

OBJ		=	$(SRC:.c=.o)

NAME		=	ai

CC		=	gcc

CFLAGS		+=	-Wall -Wextra -W

CPPFLAGS 	 	+=	-I./include/

EXEC		=	./pipes.sh

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

exec: re
	$(EXEC)

.PHONY :fclean all clean re