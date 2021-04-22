/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** my_strcat
*/

#include <stdlib.h>

char *my_strcat(char *str1, char *str2, int str1_size, int str2_size)
{
    char *new = NULL;
    int size = str1_size + str2_size;
    int pos = 0;

    if ((new = malloc(sizeof(char *) * (++size))) == NULL)
        return (NULL);
    if (str1 != NULL)
        for (int i = 0 ; i < str1_size ; i++)
            new[pos++] = str1[i];
    for (int i = 0 ; i < str2_size ; i++)
        new[pos++] = str2[i];
    new[pos] = '\0';
    free(str1);
    return (new);
}