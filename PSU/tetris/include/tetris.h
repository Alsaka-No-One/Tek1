/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_

//Return Statues
static const int SUCCESS = 0;
static const int ERROR = 84;

// Bool
typedef enum bool_e {
    false = 0,
    true = 1
} bool;

//Main Function
int tetris(int ac, char **av);

//Usefull function
char *copy_rotate(char **map, char *dest, int end_map, int col);

#endif /* TETRIS_H_ */
