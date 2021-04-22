/*
** EPITECH PROJECT, 2019
** Tetris
** File description:
** Contain all the data struct
*/

#ifndef DATA_H
#define DATA_H

#include <stdio.h>

typedef struct tetriminos_s {
    bool error;
    char *name;
    int width;
    int height;
    int color;
    char **shape;
    char **mv_shape;
} tetriminos_t;

typedef struct data_s {
    int nb_tetriminos;
    char **save_map;
    tetriminos_t *tetriminos;
    int pos_x;
    int pos_y;
    int next;
    int level;
    int key_left;
    int key_right;
    int key_turn;
    int key_drop;
    int key_quit;
    int key_pause;
    int map_row;
    int map_col;
    bool without_next;
    bool debug;
} data_t;

//Data function
data_t load_data(void);
int load_tetriminos(data_t *data);
tetriminos_t *alloc_tetriminos(data_t *data);
int fill_tetriminos(data_t *data);
int name_parser(data_t *data, char *name, int i);
int first_line_parser(data_t *data, FILE *fp, int i);
int tetrimino_parser(data_t *data, FILE *fp, int i);
int open_tetrimino(FILE **fp, char *name);
bool is_tetrimino(char *name);
bool error_first_line(data_t data, tetriminos_t tetriminos);
bool error_shape(tetriminos_t tetriminos);
int data_verif(data_t data);
void free_data(data_t data);

//Option function
void option(int ac, char **av, data_t *data);
void usage(void);
void load_map_size(data_t *data, char *optarg);
void print_debug(data_t data);
int print_tetriminos(data_t data);
void sort_tetriminos(int *isort, tetriminos_t *tetriminos, int nb_tetriminos);

//Gameloop functions
int gameloop(data_t *data);
int gameplay(char **map, data_t *data, int *loose_status);
int start_tetriminos(char **map, data_t *data, int *tetri);
void tetriminos_fall(data_t *data, int *fall, tetriminos_t *tetri, char **map);
int collision(data_t *data, tetriminos_t *tetri, int pos_x, int pos_y);
int loose_game(char **map, int fall, data_t *data, int tetri);
void print_clock(int y, int x);
void my_pause(data_t *data);

//Event
int handle_evt(char **map, data_t *data, tetriminos_t *tetri);

//Tetriminos Movement
void tetriminos_fall(data_t *data, int *fall, tetriminos_t *tetri, char **map);
void tetriminos_right(char **map, tetriminos_t *tetri, data_t *data);
void tetriminos_left(char **map, tetriminos_t *tetri, data_t *data);
void rotate(char **map, tetriminos_t *tetri, data_t *data);
void line_correct(char **map, data_t *data);
void drop_block(char **map, tetriminos_t *tetri, data_t *data);

//Create Map
char **create_map(data_t *data);

//Display
void display_map(char **map, data_t *data);

#endif /* DATA_H */
