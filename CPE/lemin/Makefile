##
## EPITECH PROJECT, 2018
## Lem-in
## File description:
## Makefile
##

NAME	=	lem_in

SRC		=	lem_in.c							\
			src/input_processing.c				\
			src/parse/parse_file.c				\
			main.c								\
			src/str_to_word_array.c				\
			src/my_getnbr.c						\
			src/my_put_nbr.c					\
			src/my_str_isnum.c					\
			src/my_putstr.c						\
			src/parse/graph.c					\
			src/my_strlen.c						\
			src/parse/parse_nb_ants.c			\
			src/parse/useful_fonctions.c		\
			src/parse/parse_tunnel.c			\
			src/parse/parse_tunnel_two.c		\
			src/parse/str_comp.c				\
			src/parse/free_array.c				\
			src/parse/useful_fonction_two.c		\
			src/parse/parse_rooms.c				\
			src/parse/parse_rooms_two.c			\
			src/parse/realloc_room.c			\
			src/strcpy.c						\
			src/parse/check_same_tunnel.c		\
			src/parse/dispa_moves.c				\
			src/parse/algo.c

TESTSRC	=	lem_in.c							\
			src/input_processing.c				\
			src/parse/parse_file.c				\
			src/str_to_word_array.c				\
			src/my_getnbr.c						\
			src/my_put_nbr.c					\
			src/my_str_isnum.c					\
			src/my_putstr.c						\
			src/parse/graph.c					\
			src/my_strlen.c						\
			src/parse/parse_nb_ants.c			\
			src/parse/useful_fonctions.c		\
			src/parse/parse_tunnel.c			\
			src/parse/parse_tunnel_two.c		\
			src/parse/str_comp.c				\
			src/parse/free_array.c				\
			src/parse/useful_fonction_two.c		\
			src/parse/parse_rooms.c				\
			src/parse/parse_rooms_two.c			\
			src/parse/realloc_room.c			\
			src/strcpy.c						\
			src/parse/check_same_tunnel.c		\
			src/parse/dispa_moves.c				\
			src/parse/algo.c					\
			tests/unit_test_one.c				\
			tests/unit_test_two.c				\
			tests/unit_test_tree.c

RMTEST	=	lem_in.gcda							\
			input_processing.gcda				\
			parse_file.gcda						\
			str_to_word_array.gcda				\
			my_getnbr.gcda						\
			my_put_nbr.gcda						\
			my_str_isnum.gcda					\
			my_putstr.gcda						\
			graph.gcda							\
			my_strlen.gcda						\
			parse_nb_ants.gcda					\
			useful_fonctions.gcda				\
			parse_tunnel.gcda					\
			parse_tunnel_two.gcda				\
			str_comp.gcda						\
			free_array.gcda						\
			useful_fonction_two.gcda			\
			parse_rooms.gcda					\
			parse_rooms_two.gcda				\
			realloc_room.gcda					\
			strcpy.gcda							\
			check_same_tunnel.gcda				\
			dispa_moves.gcda					\
			algo.gcda							\
			lem_in.gcno							\
			input_processing.gcno				\
			parse_file.gcno						\
			str_to_word_array.gcno				\
			my_getnbr.gcno						\
			my_put_nbr.gcno						\
			my_str_isnum.gcno					\
			my_putstr.gcno						\
			graph.gcno							\
			my_strlen.gcno						\
			parse_nb_ants.gcno					\
			useful_fonctions.gcno				\
			parse_tunnel.gcno					\
			parse_tunnel_two.gcno				\
			str_comp.gcno						\
			free_array.gcno						\
			useful_fonction_two.gcno			\
			parse_rooms.gcno					\
			parse_rooms_two.gcno				\
			realloc_room.gcno					\
			strcpy.gcno							\
			check_same_tunnel.gcno				\
			dispa_moves.gcno					\
			algo.gcno							\
			unit_test_one.gcda					\
			unit_test_one.gcno					\
			unit_test_two.gcda					\
			unit_test_two.gcno					\
			unit_test_tree.gcda					\
			unit_test_tree.gcno

OBJ		=	$(SRC:.c=.o)

CCO		=	gcc -o

CFLAGS	+= -I./include/ -g3

NAMETEST=	unit_test

RM		=	rm -rf

CRITER	=	--coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CCO) $(NAME) $(OBJ)

clean :
			$(RM) $(OBJ)
			$(RM) $(RMTEST)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(NAMETEST)

re:			fclean all

tests_run:
			$(CCO) $(NAMETEST) $(TESTSRC) $(CFLAGS) $(CRITER)
			./$(NAMETEST)

.PHONY:		all clean fclean re
