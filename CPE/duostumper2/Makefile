##
## EPITECH PROJECT, 2018
## name
## File description:
## Makefile
##

NAME	=	boggle

SRC		=	hidenp.c		\
			display_win.c		\
			src/boggle_3_arg.c	\
			src/my_strlen.c		\
			src/ask_word.c		\
			src/error_argument.c	\
			write_victory.c		\
			find_path_charact.c	\
			boggle.c		\
			main.c

OBJ		=	$(SRC:.c=.o)

CCO		=	gcc -o

LIB		=	-L./lib -lmy

CFLAGS	+= -I./include/ -g3

CSFML	=	-l csfml-graphics -l csfml-window -l csfml-system

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CCO) $(NAME) $(OBJ)

clean :
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
