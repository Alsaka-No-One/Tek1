##
## EPITECH PROJECT, 2019
## PSU_navy_2018
## File description:
## Makefile
##

SRC		=		main.c								\
				error_verif/input_processing.c		\
				error_verif/display_help.c			\
				gameplay/start_player.c				\
				gameplay/load_map.c					\
				navy.c								\
				error_verif/action_error_two.c		\
				error_verif/action_error_one.c		\
				gameplay/load_ships.c				\
				error_verif/verification_file.c		\
				gameplay/connection_player.c		\
				gameplay/get_position_ship.c		\
				gameplay/enemy_map.c				\
				error_verif/signal_ctrl_d.c			\
				error_verif/check_lose.c			\
				gameplay/turn_player.c				\
				gameplay/capture_signal.c			\
				gameplay/signal_sending.c			\
				gameplay/command_player.c			\
				gameplay/translate_coord.c			\
				gameplay/hit_or_miss.c				\
				gameplay/check_turn.c				\
				error_verif/free_all.c				\
				gameplay/display_map.c

TESTSRC	=		error_verif/input_processing.c		\
				error_verif/display_help.c			\
				gameplay/start_player.c				\
				gameplay/load_map.c					\
				navy.c								\
				error_verif/action_error_two.c		\
				error_verif/action_error_one.c		\
				gameplay/load_ships.c				\
				error_verif/verification_file.c		\
				gameplay/connection_player.c		\
				gameplay/get_position_ship.c		\
				gameplay/enemy_map.c				\
				error_verif/signal_ctrl_d.c			\
				error_verif/check_lose.c			\
				gameplay/turn_player.c				\
				gameplay/capture_signal.c			\
				gameplay/signal_sending.c			\
				gameplay/command_player.c			\
				gameplay/translate_coord.c			\
				gameplay/hit_or_miss.c				\
				gameplay/check_turn.c				\
				error_verif/free_all.c				\
				gameplay/display_map.c				\
				tests/unit_test_one.c				\
				tests/unit_test_two.c

RMTEST	=		input_processing.gcno				\
				display_help.gcno					\
				start_player.gcno					\
				load_map.gcno						\
				navy.gcno							\
				action_error_two.gcno				\
				action_error_one.gcno				\
				load_ships.gcno						\
				verification_file.gcno				\
				connection_player.gcno				\
				get_position_ship.gcno				\
				enemy_map.gcno						\
				signal_ctrl_d.gcno					\
				check_lose.gcno						\
				turn_player.gcno					\
				capture_signal.gcno					\
				signal_sending.gcno					\
				command_player.gcno					\
				translate_coord.gcno				\
				hit_or_miss.gcno					\
				check_turn.gcno						\
				free_all.gcno						\
				display_map.gcno					\
				unit_test_one.gcno					\
				unit_test_two.gcno					\
				unit_test_tree.gcno					\
				input_processing.gcda				\
				display_help.gcda					\
				start_player.gcda					\
				load_map.gcda						\
				navy.gcda							\
				action_error_two.gcda				\
				action_error_one.gcda				\
				load_ships.gcda						\
				verification_file.gcda				\
				connection_player.gcda				\
				get_position_ship.gcda				\
				enemy_map.gcda						\
				signal_ctrl_d.gcda					\
				check_lose.gcda						\
				turn_player.gcda					\
				capture_signal.gcda					\
				signal_sending.gcda					\
				command_player.gcda					\
				translate_coord.gcda				\
				hit_or_miss.gcda					\
				check_turn.gcda						\
				free_all.gcda						\
				display_map.gcda					\
				unit_test_one.gcda					\
				unit_test_two.gcda					\
				unit_test_tree.gcda

OBJ		=		$(SRC:.c=.o)

NAME	=		navy

NAMETEST=		unit_test

CFLAGS	+=		-I./include/ -I./lib/include/

CCO		=		gcc -o

RM		=		rm -f

LIB		=		-L./lib -lmy

CRITER	=		--coverage -lcriterion

all:			$(NAME)

$(NAME):		$(OBJ)
				make -C ./lib
				$(CCO) $(NAME) $(OBJ) $(LIB) -g3
				make clean

clean:
				$(RM) $(OBJ)
				make clean -C ./lib
				$(RM) $(RMTEST)

fclean:			clean
				$(RM) $(NAME)
				make fclean -C ./lib
				$(RM) $(NAMETEST)

re:				fclean all

tests_run:
			$(CCO) $(NAMETEST) $(TESTSRC) $(LIB) $(CFLAGS) $(CRITER)
			./$(NAMETEST)
