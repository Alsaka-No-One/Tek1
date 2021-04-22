##
## EPITECH PROJECT, 2018
## shell 2
## File description:
## Makefile
##

NAME	=	mysh

SRC		=	src/arg_gestion.c			\
			src/usefull_function.c		\
			src/usefull_function2.c		\
			src/setenv.c				\
			src/unsetenv.c				\
			src/my_exit.c				\
			src/my_getnbr.c				\
			src/free_tab.c				\
			src/separate_to_arg.c		\
			src/separate_to_arg2.c		\
			src/get_command.c			\
			src/cd.c					\
			src/analyse_exec.c			\
			src/invalid_command.c		\
			src/find_path.c				\
			src/my_exec.c				\
			src/get_env.c				\
			src/realloc.c				\
			src/strcpy.c				\
			src/env.c					\
			minishell.c					\
			main.c

OBJ		=	$(SRC:.c=.o)

CCO		=	gcc -o

LIB		=	-L./lib -lmy

CFLAGS	+= -I./include/ -g3 -Wall -Wextra -Werror

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
