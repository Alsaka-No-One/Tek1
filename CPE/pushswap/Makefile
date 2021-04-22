##
## EPITECH PROJECT, 2018
## CPE pushswap
## File description:
## Makefile
##

NAME		=	push_swap

SRC		=	src/operation_allowed.c 		\
			src/operation_allowed_vtwo.c 	\
			src/algo.c						\
			src/check_sort.c 				\
			src/error_argument.c 			\
			main.c

OBJ		=	$(SRC:.c=.o)

CCO		=	gcc -o

LIB		=	-L./lib -lmy

all:			$(NAME)

$(NAME):		$(OBJ)
			make -C ./lib
			$(CCO) $(NAME) -g3 $(OBJ) $(LIB)

clean :
			rm -rf $(OBJ)
			make clean -C ./lib

fclean:			clean
			rm -rf $(NAME)
			make fclean -C ./lib

re:			fclean all

.PHONY:			all clean fclean re
