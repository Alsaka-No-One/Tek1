##
## EPITECH PROJECT, 2018
## bootstrap my hunter | Makefile
## File description:
## Makefile
##

NAME	=	42sh

SRC	=	src/main.c\
		src/minishell.c\
		src/print.c\
		src/str_cmp.c\
		src/get_first_word.c\
		src/my_str_to_word_array.c\
		src/array_gest.c\
		src/str_conc.c\
		src/array_remove.c\
		src/get_number.c\
		src/text_gest.c\
		src/parser.c\
		src/split_parser.c\
		src/chain_list/add_element.c\
		src/chain_list/binary_tree.c\
		src/command/edit_env.c\
		src/command/make_exec.c\
		src/command/command_handler.c\
		src/command/split_command.c\
		src/command/verif_arg.c\
		src/command/input_pipe.c\
		src/command/cmd_separator.c\
		src/command/exec_command.c\
		src/get_arg.c\
		src/tool/only_space.c\
		src/tool/get_exec_path.c\
		src/builtin/my_exit.c\
		src/builtin/my_echo.c\
		src/builtin/my_history.c\
		src/builtin/my_excla.c\
		src/builtin/my_cd/my_cd.c\
		src/builtin/my_cd/my_cd_no_arg.c\
		src/builtin/my_cd/my_cd_setenv.c\
		src/builtin/my_cd/my_cd_malus.c\
		src/builtin/my_env.c\
		src/builtin/my_setenv.c\
		src/builtin/my_unsetenv.c\
		src/fill_history.c\
		src/tool/is_word_in_str.c\
		src/tool/jump_space.c\
		src/tool/copy_command.c\
		src/builtin/aliases/all_alias1.c\
		src/builtin/aliases/all_alias2.c\
		src/builtin/aliases/all_alias3.c\
		src/builtin/localvar/all_local1.c\
		src/builtin/localvar/all_local2.c\
		src/builtin/localvar/all_local3.c

OBJ		=	$(SRC:.c=.o)

CC		= 	gcc

CFLAGS	=	-I./include -L./lib/mlib -lm

CRITERION = --coverage -lcriterion


all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/mlib
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
clean :
	make clean -C ./lib/mlib
	rm -rf $(OBJ)

fclean:	clean
	make fclean -C ./lib/mlib
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
