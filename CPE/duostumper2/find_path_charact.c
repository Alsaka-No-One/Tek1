/*
** EPITECH PROJECT, 2019
** duo stumper 2
** File description:
** find path charact
*/

#include "my.h"

int check_letters(char **map, char word, int linum, int j)
{
    if (word != '\0')
        if (map[linum - 1][j] != word
            && map[linum - 1][j - 2] != word
            && map[linum - 1][j + 2] != word
            && map[linum][j - 2] != word
            && map[linum][j + 2] != word
            && map[linum + 1][j] != word
            && map[linum + 1][j - 2] != word
            && map[linum + 1][j + 2] != word) {
            return (ERROR);
        }
    return (SUCCESS);
}

int check_path(char **map, char *word)
{
    int i = 0;
    int j = 2;
    int linum = 1;
    int status = 0;

    while (word[i] != '\0') {
        if (j == 9) {
            j = 2;
            linum += 1;
        }
        if (map[linum][j] == word[i]) {
            status = check_letters(map, word[i + 1], linum, j);
            i++;
        }
        if (status == ERROR)
            return (ERROR);
        j++;
    }
    return (SUCCESS);
}
