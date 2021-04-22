/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** get_champ_comment
*/

#include <stdlib.h>

char *get_champ_comment(char *content, int *index, int size)
{
    char *comment = NULL;
    int comment_size = 0;

    for ( ; *index < size && content[*index] == 0x00; (*index)++);
    (*index)++;
    for (int i = *index ; i < size && content[i] != 0x00; i++, comment_size++);
    comment = malloc(sizeof(char) * (comment_size + 1));
    if (comment == NULL)
        return (NULL);
    (*index)++;
    for (int i = 0; *index < size && i < comment_size; (*index)++, i++)
        comment[i] = content[*index];
    comment[comment_size] = '\0';
    (*index)++;
    return (comment);
}