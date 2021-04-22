/*
** EPITECH PROJECT, 2019
** Solo stumper 1 | sort
** File description:
** The function to sort in alphabetial order
*/

#include "stumper.h"

char *check_first(int i, int j, char *words, char *new_words)
{
    int save = i;
    int save2 = j;

    if (words[j] <= words[i] || words[j] == words[i] + 32 || words[j] == words[i] - 32) {
        while (words[j] != '|') {
            new_words[j] = words[j];
            j++;
        }
        new_words[i - 1] = '|';
        while (words[i] != '|') {
            new_words[i] = words[i];
            i++;
        }
        return (new_words);
    }
    else {
        while (words[i] != '|' && words[i] != '\0') {
            new_words[j] = words[i];
            j++;
            i++;
        }
        new_words[save - 1] = '|';
        while (words[save2] != '|' && words[save2] != '\0') {
            new_words[save] = words[save2];
            save2++;
            save++;
        }
    }
    return (new_words);
}

char *swap(char *words)
{
    char *new_words;
    int i = 0;
    int j = 0;

    if (words[0] >= 'A' && words[0] <= 'Z' || words[0] >= 'a' && words[0] <= 'z')
        j = 0;
    new_words = malloc(sizeof(char) * my_strlen(words));
    while (words[i] != '\0') {
        if (words[i] == '|')
           new_words = check_first(i + 1, j, words, new_words);
        i++;
    }
    return (new_words);
}
