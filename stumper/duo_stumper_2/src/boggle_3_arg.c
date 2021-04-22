/*
** EPITECH PROJECT, 2019
** duostumper 
** File description:
** bogle
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int error_size_map(char *nbr)
{
    int check = my_strlen(nbr);

    if (check != 16)
        return (ERROR);
    return (0);
}

char **create_fix_map(void)
{
    char **map = NULL;

    if ((map = malloc(sizeof(char *) * 7)) == NULL)
        return (NULL);
    for (int i = 0; i <= 6; i++) {
        if ((map[i] = malloc(sizeof(char) * 13)) == NULL)
            return (NULL);
        map[i][12] = '\0';
    }
    for (int i = 0; i != 11; i++) {
        map[0][i] = '+';
        map[5][i] = '+';
    }
    map[6] = NULL;
    return (map);
}

void fill_letters(char **map, char *str)
{
    int i = 0;
    int j = 2;
    int linum = 1;

    while (str[i] != '\0') {
        if (j == 9) {
            j = 2;
            linum += 1;
        }
        if (j % 2 == 0) {
            map[linum][j] = str[i];
            i++;
        }
        j++;
    }
}

void fill_first_tab(char **map)
{
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j != 11; j++)
            map[i][j] = ' ';
        map[i][0] = '|';
        map[i][10] = '|';
    }
}

int boggle_3_argument(char **argv)
{
    char **map = create_fix_map();

    if (error_size_map(argv[2]) == ERROR) {
        write(2, "Invalid number of letters for the grill\n", 40); 
        return (ERROR);
    }
    fill_first_tab(map);
    fill_letters(map, argv[2]);
    for (int i = 0; map[i] != NULL; i++)
        printf("%s\n", map[i]);
    return (ask_word(map, argv[2]));
}
