/*
** EPITECH PROJECT, 2019
** duo stumper 2
** File description:
** Display win
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int display_win(char *word, char *tab)
{
    char **map = create_fix_map();

    if (map == NULL) {
        write(2, "Map hasn't been malloc\n", 23);
        return (ERROR);
    }
    fill_first_tab(map);
    fill_letters(map, tab);
    if (check_path(map, word) == ERROR)
        return (ERROR);
    write_victory(map, word);
    for (int i = 0; map[i] != NULL; i++)
        printf("%s\n", map[i]);
    return (0);
}
