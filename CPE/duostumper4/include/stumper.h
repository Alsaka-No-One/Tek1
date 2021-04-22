/*
** EPITECH PROJECT, 2019
** duostumper
** File description:
** include
*/

#ifndef STUMPER_H_
#define STUMPER_H_

static const int SUCCESS = 0;
static const int ERROR = 84;

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct pokemon_s {
    char *name;
    int attack;
    int defense;
    int speed;
    int health;
} pokemon_t;

typedef struct fight_s {
    pokemon_t pokemon1;
    pokemon_t pokemon2;
    pokemon_t list[99];
} fight_t;

int com_or_not(char *str);
int parser(char **argv, fight_t *fight);
int imput(int argc, char **argv);
int turn2(fight_t *fig, int call);
int verif_win(fight_t *fig);
int turn1(fight_t *fig, int call);
int battle(fight_t *fig);
char *mstrcat(char *dest, char *src);
char **st_to_ar(char *str);
void make_struct(fight_t *fight, char *str, int *i);

#endif
