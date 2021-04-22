/*
** EPITECH PROJECT, 2019
** crocus
** File description:
** ascii representation of numbers
*/

#include <stddef.h>
#include "stumper.h"

static int verif_pos(char **av, int pos_nbrs)
{
    for (pos_nbrs = 0; av[pos_nbrs][0] != '-' || av[pos_nbrs][1] != 'n'
             || av[pos_nbrs][2] != '\0'; pos_nbrs++);
    pos_nbrs++;
    return (pos_nbrs);
}

static char **fill_3(char ch, char **show, int *nbr, char symp)
{
    switch(ch) {
    case '7':
        write_7(show, symp, nbr);
        *nbr += 6;
        break;
    case '8':
        write_8(show, symp, nbr);
        *nbr += 6;
        break;
    case '9':
        write_9(show, symp, nbr);
        *nbr += 6;
        break;
    }
    return (show);
}

static char **fill_2(char ch, char **show, int *nbr, char symp)
{
    switch(ch) {
    case '3':
        write_3(show, symp, nbr);
        *nbr += 6;
        break;
    case '4':
        write_4(show, symp, nbr);
        *nbr += 6;
        break;
    case '5':
        write_5(show, symp, nbr);
        *nbr += 6;
        break;
    case '6':
        write_6(show, symp, nbr);
        *nbr += 6;
        break;
    default:
        show = fill_3(ch, show, nbr, symp);
    }
    return (show);
}

int fill_show(char **av, int pos_nbrs, char **show, char symb)
{
    int nbr = 0;

    for (int comp = 0; av[pos_nbrs][comp] != '\0'; comp++) {
        switch (av[pos_nbrs][comp]) {
        case '0':
            write_0(show, symb, &nbr);
            nbr += 6;
            break;
        case '1':
            write_1(show, symb, &nbr);
            nbr += 6;
            break;
        case '2':
            write_2(show, symb, &nbr);
            nbr += 6;
            break;
        default:
            show = fill_2(av[pos_nbrs][comp], show, &nbr, symb);
        }
    }
}

int crocus(char **av)
{
    int pos_nbrs;
    int pos_string;
    int com;
    char **show;

    pos_nbrs = verif_pos(av, pos_nbrs);
    for (com = 0; av[pos_nbrs][com] != '\0'; com++);
    if ((show = malloc (sizeof(char *) * 6)) == NULL)
        return (84);
    for (int ui = 0; ui < 6; ui++)
        if ((show[ui] = malloc(sizeof(char) * (com * 6 + 1))) == NULL)
            return (84);
    for (pos_string = 0; av[pos_string][0] != '-' || av[pos_string][1] != 's'
             || av[pos_string][2] != '\0'; pos_string++) {
        if (av[pos_string + 1] == NULL) {
            pos_string = 0;
            break;
        }
    }
    fill_tab(&show, (com * 6));
    if (pos_string != 0)
        pos_string++;
    return (find_symbol(pos_string, av, pos_nbrs, show));
}
