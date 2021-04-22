##
## EPITECH PROJECT, 2018
##
## File description:
## Makefile
##

SRC	=	src/main.c			\
		src/tetris.c			\
		src/gameloop.c			\
		src/gameplay.c			\
		src/create_map.c		\
		src/display.c			\
		src/load_data.c			\
		src/load_tetriminos.c		\
		src/alloc_tetriminos.c		\
		src/fill_tetriminos.c		\
		src/data_parser.c		\
		src/open_tetrimino.c		\
		src/is_tetrimino.c		\
		src/error_data.c		\
		src/start_tetriminos.c		\
		src/tetriminos_mvt.c		\
		src/line_correct.c		\
		src/handle_evt.c		\
		src/loose_game.c		\
		src/option.c			\
		src/pause.c				\
		src/usage.c			\
		src/load_map_size.c		\
		src/print_debug.c		\
		src/check_collision.c		\
		src/copy_rotate.c		\
		src/print_tetriminos.c		\
		src/sort_tetriminos.c		\
		src/data_verif.c		\
		src/print_clock.c		\

OBJ	=	$(SRC:.c=.o)

CCO	=	gcc -o

CFLAGS	=	-I./include/ -L./lib/mlib -lm -Wall -Wextra -Werror

NAME	=	tetris

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/mlib/
	$(CCO) $(NAME) -lncurses $(OBJ) $(CFLAGS)

clean :
	make clean -C ./lib/mlib/
	rm -rf $(OBJ)

fclean:	clean
	make fclean -C ./lib/mlib/
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
