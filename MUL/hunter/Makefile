##
## EPITECH PROJECT, 2018
## My_hunter | Makefile
## File description:
## Makefile 
##

NAME		=	my_hunter

SRC		=	src/create_window.c		\
			src/display.c			\
			manage_event.c			\
			sprite.c			\
			src/initialize_rect.c		\
			src/clock.c			\
			src/draw_all.c			\
			src/moove_bird.c		\
			src/respawn_duck.c		\
			adding_score.c			\
			main.c

OBJ		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
			make -C ./lib
			gcc -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-window -l csfml-system -L./lib -lmy

clean :
			rm -rf $(OBJ)
			make clean -C ./lib

fclean:			clean
			rm -rf $(NAME)
			make fclean -C ./lib

re:			fclean all

.PHONY:			all clean fclean re
