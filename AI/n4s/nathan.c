/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** nathan
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int nxtnbr(char *str, int *u)
{
    int i = *u;
    long nb = 0;

    for (;(((str[i] < '0') || (str[i] > '9')) && (str[i] != '\0')); i++);
    for (;(str[i] && str[i] >= '0' && str[i] <= '9'); i++)
        nb = nb * 10 + (str[i] - 48);
    *u = i;
    return (nb);
}

char *get_line(void)
{
    char *line = NULL;
    size_t len = 0;

    getline(&line, &len, stdin);
    return (line);
}

int *tableau(void)
{
    int i = 0;
    int c = 3;
    char *line;
    int *tab = malloc(sizeof(int) * 33);

    fprintf(stdout, "GET_INFO_LIDAR\n");
    line = get_line();
    if (line[0] == '1')
        for (; i != 32; i++) {
            tab[i] = nxtnbr(line, &c);
            nxtnbr(line, &c);
        }
    return (tab);
}

float get_lil(int *tab)
{
    int save = 0;

    for (int ui = 1; ui != 32; ui++)
        if (tab[ui] < tab[save])
            save = ui;
    return (save);
}

int magic(int *tab)
{
    for (int i = 12; i != 20; i++)
        if (tab[i] < 2000)
            return (1);
    return (0);
}
