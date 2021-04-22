##
## EPITECH PROJECT, 2018
## MAths | 102architect
## File description:
## Makefile
##

NAME		=	102architect	

INCLUDE		=	-I./include/

SRC		=	main.c			\
			get_vector.c		\
			help.c			\
			my_str_eg.c		\
			translation.c		\
			scaling.c		\
			rotation.c		\
			reflection.c		\
			struct_to_tab.c		\
			display_result.c	\
			check_error.c	

OBJ		=	$(SRC:.c=.o)

CCO		=	gcc -o

all:			$(NAME)

$(NAME):
			$(CCO) $(NAME) -lm $(SRC) $(INCLUDE)

clean :
			rm -rf $(OBJ)

fclean:			clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
