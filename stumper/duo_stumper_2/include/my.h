/*
** EPITECH PROJECT, 2019
** duostumper 2
** File description:
** stumper
*/

#ifndef STUMPER_H_
#define STUMPER_H_

static const int SUCCESS = 0;
static const int ERROR = 84;

int nb_char_str(char *str);
int display_win(char *word, char *tab);
int find_str(char *str, char *str2);
int ask_word(char **map, char *word);
int check_string(char *str, char *str2, char **argv);
int boggle(int ac, char **av);
int my_strlen(char const *str);
int error_argument(int argc, char **argv);
int boggle_3_argument(char **argv);
void fill_first_tab(char **map);
char **create_fix_map(void);
int error_size_map(char *nbr);
void fill_letters(char **map, char *str);
void write_victory(char **map, char *str);
int check_letters(char **map, char word, int linum, int j);
int check_path(char **map, char *word);

#endif
