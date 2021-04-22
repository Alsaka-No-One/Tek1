/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** get_champ_code
*/

#include <unistd.h>
#include <stdlib.h>

char *get_champ_code(char *content, int *index, int size)
{
    char *code = NULL;
    int code_size = 0;
    int it = 0;

    for ( ; *index < size && content[*index] == 0x00; (*index)++);
    for (int i = *index ; i < size ; i++, code_size++);
    it = (*index);
    code = malloc(sizeof(char) * code_size);
    if (code == NULL)
        return (NULL);
    (*index)++;
    for (int i = 0; i < code_size; it++, i++)
        code[i] = content[it];
    (*index)++;
    return (code);
}