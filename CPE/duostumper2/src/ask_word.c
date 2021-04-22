/*
** EPITECH PROJECT, 2019
** duostumper 2
** File description:
** ask_word
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static int draw(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        printf("%s\n", map[i]);
    return (SUCCESS);
}

int ask_word(char **map, char *word)
{
    char *str = NULL;
    char *new_str = NULL;
    size_t size = 0;

    if (getline(&str, &size, stdin) == -1)
        return (ERROR);
    if ((new_str = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
        return (ERROR);
    for (int i = 0; str[i] != '\n'; i++)
        new_str[i] = str[i];
    new_str[my_strlen(new_str) + 1] = '\0';
    if (find_str(new_str, word) == -1) {
        printf("The word ''%s'' is not in the grid.\n", new_str);
        return (ERROR);
    }
    if (check_path(map, new_str) != ERROR)
        return (ERROR);
    write_victory(map, new_str);
    return (draw(map));
}
