##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## infinadd
##

SRC	=	infin_add.c

OBJ	=	$(infin_add)

NAME	=	infin_add

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/./
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy

clean:
	rm -f $(OBJ)

fclean:	clean
	rm ../lib/my/libmy.a

re:	fclean all	
