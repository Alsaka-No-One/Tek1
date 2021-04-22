##
## EPITECH PROJECT, 2018
## matchstick
## File description:
## Makefile
##

NAME	=	matchstick

SRC		=	src/create_map.c		\
			src/loop.c				\
			src/help.c				\
			src/remove_condition.c	\
			src/print_turn.c		\
			src/new_map.c			\
			src/ai.c				\
			src/ai_two.c			\
			main.c

OBJ		=	$(SRC:.c=.o)

CCO		=	gcc -o

LIB		=	-L./lib -lmy

CFLAGS	+= -I./include/ -I./lib/include/ -Wall -Wextra -Werror

CSFML	=	-l csfml-graphics -l csfml-window -l csfml-system

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C ./lib
			$(CCO) $(NAME) -g3 $(OBJ) $(LIB)

clean :
			rm -rf $(OBJ)
			make clean -C ./lib

fclean:		clean
			rm -rf $(NAME)
			make fclean -C ./lib

re:			fclean all

.PHONY:		all clean fclean re
