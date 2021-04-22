##
## EPITECH PROJECT, 2019
## label
## File description:
## Makefile
##

NAME	=	asm

SRC		=	src/label.c				\
			src/analyse.c			\
			src/my_itoa.c			\
			src/verif_command.c		\
			src/cmds_len_1.c		\
			src/cmds_len_2.c		\
			src/cmds_len_3.c		\
			src/replace_labels_1.c	\
			src/replace_labels_2.c	\
			src/write_file.c		\
			src/write_cmds_1.c		\
			src/write_cmds_2.c		\
			src/write_cmds_3.c		\
			src/write_cmds_4.c		\
			src/write_nb.c			\
			src/error.c				\
			src/verify_labels.c		\
			src/main.c				\
			src/verif_cmds_1.c		\
			src/verif_cmds_2.c		\
			src/verif_cmds_3.c		\
			src/verif_cmds_4.c		\
			src/gestion_arguments.c

OBJ		=	$(SRC:.c=.o)

CCO		=	gcc -o

LIB		=	-L./lib -lmy

CPPFLAGS = -I./include/

CFLAGS	+= 	-g3 -Wall -Wextra

CRITER	=	--coverage -lcriterion

RM		=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CCO) $(NAME) $(OBJ)

clean :
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re: clean fclean all

test: all
			./$(NAME)

.PHONY:		all clean fclean re
