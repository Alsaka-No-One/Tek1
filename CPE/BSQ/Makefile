##
## EPITECH PROJECT, 2018
## CPE BSQ | Makefile
## File description:
## Makefile
##

NAME		=	bsq

SRC		=	src/error.c			\
			src/get_file.c			\
			src/fs_print_first_line.c 	\
			src/pass_the_first_line.c	\
			src/string_to_tab.c		\
			src/tab_to_int_tab.c		\
			src/to_find_square.c		\
			src/get_coord_square.c		\
			src/draw_square.c		\
			main.c

OBJ		=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
			make -C ./lib
			gcc -o $(NAME) $(OBJ) -L./lib -lmy

clean :
			rm -rf $(OBJ)
			make clean -C ./lib

fclean:			clean
			rm -rf $(NAME)
			make fclean -C ./lib

re:			fclean all

.PHONY:			all clean fclean re
