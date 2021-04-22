##
## EPITECH PROJECT, 2018
## MUL runner
## File description:
## Makefile
##

NAME	=	my_runner

ARG	=	a

SRC		=	src/create_window.c		\
			sprite.c				\
			src/moove_character.c	\
			src/clock.c				\
			src/draw_all.c			\
			src/manage_event.c		\
			src/draw_parallax.c		\
			src/start.c				\
			src/get_file.c			\
			src/help.c				\
			src/create_map.c		\
			main.c

OBJ		=	$(SRC:.c=.o)

CCO		=	gcc -o

LIB		=	-L./lib -lmy

CFLAGS	+= -I./include/ 

CSFML	=	-l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C ./lib
			$(CCO) $(NAME) -g3 -lm $(OBJ) $(CSFML) $(LIB)

clean :
			rm -rf $(OBJ)
			make clean -C ./lib

fclean:		clean
			rm -rf $(NAME)
			make fclean -C ./lib

re:			fclean all

exe:		re
		./$(NAME) $(ARG)

.PHONY:		all clean fclean re
