##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC		=	main.c						\
			src/create_window.c			\
			src/create_vector.c			\
			src/create_menu.c			\
			src/button.c				\
			src/text.c					\
			src/initialize_sprite.c		\
			src/create_cursor.c			\
			src/create_rect.c			\
			src/create_game.c			\
			src/int_to_char.c			\
			src/drag_and_drop.c			\
			src/upgrade_tower.c			\
			src/menu_pause.c			\
			src/score.c					\
			src/type_tower_place.c		\
			src/life_rect.c				\
			src/type_up_tower.c			\
			my_defender.c				\
			src/tower_rect.c			\
			src/menu.c					\
			src/destroy.c				\
			src/analyse_arg.c			\
			src/path_minion.c			\
			src/destroy2.c				\
			src/display_tuto.c			\
			src/clock.c					\
			src/display_menu_pause.c	\
			src/tower_attack.c

NAME	=	my_defender

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

INCLUDE	=	-I./include/

CCO		=	gcc -o

RM		=	rm -f

all:		$(NAME)

$(NAME):
			$(CCO) $(NAME) $(SRC) $(CSFML) $(INCLUDE)

clean:
			$(RM) main.o

fclean:		clean
			$(RM) $(NAME)

re:			fclean all


