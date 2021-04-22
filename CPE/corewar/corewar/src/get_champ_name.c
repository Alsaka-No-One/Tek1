/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** get_champ_name
*/

#include <stdlib.h>

char *get_champ_name(char *content, int *index, int size)
{
    char *name = NULL;
    char temp = 0xf3;
    int name_size = 0;

    for ( ; *index < size && content[*index] != temp; (*index)++);
    for (int i = *index ; i < size && content[i] != 0x00; i++, name_size++);
    name = malloc(sizeof(char) * (name_size + 1));
    if (name == NULL)
        return (NULL);
    (*index)++;
    for (int i = 0; *index < size && i < name_size; (*index)++, i++)
        name[i] = content[*index];
    name[name_size] = '\0';
    (*index)++;
    return (name);
}