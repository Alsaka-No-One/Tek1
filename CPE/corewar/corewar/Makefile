##
## EPITECH PROJECT, 2018
##
## File description:
## Makefile
##

NAME	=	corewar

SRC		=	src/main.c						\
			src/gestion_argument.c			\
			src/display_help.c				\
			src/vm.c						\
			src/create_map.c				\
			src/load_champion.c				\
			src/get_champ_name.c			\
			src/get_champ_comment.c			\
			src/get_champ_code.c			\
			src/dump_memory.c				\
			src/place_champion.c			\
			src/fill_data.c					\
			src/multiple_definition.c		\
			src/multiple_memory.c			\
			src/take_nb_bytes.c				\
			src/memory_champ.c				\
			src/exec_champion.c				\
			src/op.c						\
			src/load_value.c				\
			src/instruction_end.c			\
			src/champion_func/champ_live.c	\
			src/champion_func/champ_ld.c	\
			src/champion_func/champ_st.c	\
			src/champion_func/champ_add.c	\
			src/champion_func/champ_sub.c	\
			src/champion_func/champ_and.c	\
			src/champion_func/champ_or.c	\
			src/champion_func/champ_xor.c	\
			src/champion_func/champ_zjmp.c	\
			src/champion_func/champ_ldi.c	\
			src/champion_func/champ_sti.c	\
			src/champion_func/champ_fork.c	\
			src/champion_func/champ_lld.c	\
			src/champion_func/champ_lldi.c	\
			src/champion_func/champ_lfork.c	\
			src/champion_func/champ_aff.c	\
			src/tools/my_strcmp.c			\
			src/tools/my_strlen.c			\
			src/tools/mgetnbr.c				\
			src/tools/put.c					\
			src/tools/my_strcpy.c			\
			src/tools/mputnbr.c				\
			src/tools/my_strcat.c			\
			src/tools/bytes_to_int.c		\
			src/tools/print_in_mem.c

OBJ		=	$(SRC:.c=.o)

CCO		=	gcc -o

LIB		=	-L./lib -lmy

CFLAGS	+= 	-I./include/ -Wall -Wextra -Werror -g3

CRITER	=	--coverage -lcriterion

RM		=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CCO) $(NAME) $(OBJ)

clean :
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

tests_run:
			$(CCO) $(NAMETEST) $(SRCTEST) $(CFLAGS) $(CRITER)
			./$(NAMETEST)

.PHONY:		all clean fclean re
