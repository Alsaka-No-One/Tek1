/*
** EPITECH PROJECT, 2019
** fractal
** File description:
** draw_fractal
*/

#include <stdlib.h>
#include <unistd.h>
#include "fractal.h"

static char *concat_string(char **av)
{
    char *str = malloc(sizeof(char)
                       * (my_strlen(av[2]) + my_strlen(av[3])));
    int j = 0;
    int status = 2;

    if (str == NULL) {
        write(2, "Error with malloc\n", 18);
        return (NULL);
    }
    for (int i = 0; (i != (my_strlen(av[2]) + my_strlen(av[3]) + 1))
             && (av[3][j] != '\0'); i++) {
        if (status == 2) {
            str[i] = av[status][i];
            (av[status][i] == '\0') ? str[i] = '@' : 0;
            (av[status][i] == '\0') ? status += 1 : 0;
        } else {
            str[i] = av[status][j];
            j++;
        }
    }
    return (str);
}

static int draw_fractal2(char **av, int i)
{
    char *str = NULL;

    if ((str = concat_string(av)) == NULL)
        return (84);
    replace_str(str, '@', '\n');
    my_putstr(str);
}

int draw_dractal(char **av, int i)
{
    char *str = malloc(sizeof(char) * i);

    if (str == NULL) {
        write(2, "Error with malloc\n", 18); 
        return (84);
    }
    if (av[1][0] == '1') {
        str = replace_str(av[2], '@', '\n');
        my_putstr(str);
    }
    else if (av[1][0] == '2')
        if (draw_fractal2(av, i) == 84)
            return (84);
    my_putchar('\n');
    return (0);
}
