/*
** EPITECH PROJECT, 2019
** Solo stumper 1 | words
** File description:
** The function to seperate the words
*/

#include "stumper.h"

char *regroup_words(char *argv)
{
    int i = 0;
    int j = 0;
    char *words = NULL;

    words = malloc(sizeof(char) * my_strlen(argv));
    while (argv[i] != '\0') {
        if (argv[i] == ' ') {
            words[j] = '|';
        }
        else {
            words[j] =argv[i];
        }
        i++;
        j++;
    }
    return (words);
}
