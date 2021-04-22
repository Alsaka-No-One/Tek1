/*
** EPITECH PROJECT, 2018
** CPE BSQ | pass_the_first_line
** File description:
** A function to don't display the first line
*/

#include "../include/bsq.h"
#include <stdio.h>

char *pass_the_first_line(char *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * my_strlen(src));
    int j = 0;

    if (dest == NULL)
        exit(84);
    while (src[i] != '\n')
        i++;
    i++;
    while (src[i] != '\0') {
        dest[j] = src[i];
        j++;
        i++;
    }
    dest[j] = '\0';
    return (dest);
}
