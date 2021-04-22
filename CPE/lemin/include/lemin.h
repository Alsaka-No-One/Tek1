/*
** EPITECH PROJECT, 2019
** header
** File description:
** Header
*/

#ifndef _LEMIN_H_
#define _LEMIN_H_

static const int ERROR = 84;
static const int SUCCESS = 0;

#define VERIF_MALLOC(str) if ((str) == NULL) return (NULL);
#define VERIF_INT_MALLOC(str) if ((str) == NULL) return (ERROR);

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "struct.h"

int input_processing(int argc, char **argv);
int lemin(void);
int parse_file(void);
int my_strlen(char const *str);
char **realloc_double_tab(char **file);
int my_str_isnum(char const *str);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_getnbr(char const *str);
int error_gestion(char **file);
int graph(parse_t *parse);
char **str_to_word_array(char const *str);
void find_nb_ants(char *str, int *status, parse_t *parse);
void check_room(char *str, int *status, parse_t *parse);
void free_array(char **array);
char *check_com(char *str);
int com_or_not(char *str);
char **get_arg_str(char *str, char **array);
int double_tab_len(char **array);
int my_strcomp(char const *str, char const *comp_str);
void check_tunnel(char *str, int *status, parse_t *parse);
int my_str_isalphanum(char *str);
char *my_getstr(char *str);
room_t *realloc_rooms(room_t *parse, int size);
int get_room(parse_t *parse, char **array);
int check_name_coord(char *str, int x, int y, parse_t *parse);
int get_name_and_coord(char **array, parse_t *parse);
void check_room_norme(char **array, int *status, parse_t *parse);
int detect_start_end(char *str, parse_t *parse);
void check_room(char *str, int *status, parse_t *parse);
int go_tunnel(parse_t *parse, int *status, char *str);
void display_room(parse_t *parse, int size);
char *my_strcpy(char *dest, char *src);
char **remalloc(char **file);
int my_strlen(char const *str);
char *fill_string(char *src, char *dest, int status);
int check_same_tunnel(parse_t *parse, char *str, int *status);
int tunnel_or_not(char const *str);
int name_gestion(char *name, char *name2, parse_t *parse, int *status);
int check_name(char *name, parse_t *parse);
int algo(parse_t *parse);
int disp_moves(parse_t *parse);
void show_res(parse_t *parse, int nb);

#endif
