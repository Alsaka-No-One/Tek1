/*
** EPITECH PROJECT, 2019
** duostumper
** File description:
** include
*/

#ifndef _STUMPER_H_
#define _STUMPER_H_

static const int SUCCESS = 0;
static const int ERROR = 84;

typedef struct data_s {
    char player_one_symb;
    char player_two_symb;
    int size;
    int pasta;
} data_t;

//Arg Gestion
int check_arg(int argc, char **argv);
int fill_data(int argc, char **argv);

//Gameloop
int game(data_t *data);

//Display
void display(char **map);

//verifs
void verifs(data_t *dat, char **arr, int row, int line);
int check_input(char *str);

//Victory and Draw
int victory_line(char *map, data_t *data);
int victory_cols(char **map, int i, data_t *data);
int draw(char **map);
int victory_diagonal(char **map, data_t *data);
int victory_up_diagonal(char **map, data_t *data);
int victory(char **map, data_t *data);

#endif
