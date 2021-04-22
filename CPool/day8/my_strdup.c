/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** strdup
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = 0;
    char *dest;

    dest = malloc (my_strlen (src) + 1);
    if (dest == NULL){
        return (NULL);
    }
    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
