/*
** EPITECH PROJECT, 2018
** infin add
** File description:
** add infinite number
*/

#include <stdlib.h>
#include "include/list.h"

int addlink(t_list *list, char *i)
{
    t_list *rev;

    rev = malloc (sizeof(t_list));
    if (rev = NULL)
        return (rev);
    rev -> i = i;
    rev -> next = list;
    return (rev);
}

void printlink(t_list *list)
{
    while (list) {
        my_putstr (list->i);
        list = list->next;
    }
}

void result(char *term1, char *term2)
{
    char *i = 0;
    int mind = 0;
    int sizeterm1 = my_strlen (term1) - 1;
    int sizeterm2 = my_strlen (term2) - 1;
    t_list *list;

    list = NULL;
    while (sizeterm1 >= 0 && sizeterm2 >= 0) {
        i = term1[sizeterm1] + term2[sizeterm2] + mind - 2 * 48;
        mind = 0;
        if (i > 9) {
            i = i - 10;
            mind = 1;
            if (sizeterm1 == 0 && sizeterm2 == 0)
                i = i + 10;
        }
        my_put_nbr(i);
        sizeterm1--;
        sizeterm2--;
    }
    my_putchar ('\n');
}

int main(int argc, char **argv)
{
    if (argc == 3) {
        result (argv[1], argv[2]);
        return (0);
    }
    return (84);
}
