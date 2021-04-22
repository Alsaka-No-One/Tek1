/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** Task02
*/

#include "shell.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int my_strcomp(char const *str, char const *str_comp)
{
    int i = 0;

    if (my_strlen(str) != my_strlen(str_comp))
        return (-1);
    for (; str[i] != '\0'; i++)
        if (str[i] != str_comp[i])
            return (-1);
    return (1);
}

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

char *realloc_str(char *str, int nb)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + nb));

    if (new_str == NULL)
        return (NULL);
    new_str = my_strcpy(new_str, str);
    return (new_str);
}

char *my_strcat_path(char *dest, char *src)
{
    int i = 0;
    int j = 0;

    dest = realloc_str(dest, (my_strlen(src) + 2));
    if (dest == NULL)
        return (NULL);
    while (dest[i] != '\0')
        i++;
    dest[i] = '/';
    i++;
    while (src[j] != '\0') {
        dest[i] = src[j];
        i += 1;
        j += 1;
    }
    dest[i] = '\0';
    return (dest);
}