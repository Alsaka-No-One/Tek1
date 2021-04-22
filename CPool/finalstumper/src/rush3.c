/*
** EPITECH PROJECT, 2018
** rush3
** File description:
** rush 3
*/

#include "rush3.h"
#include "mylibc.h"

bool check_rush3(char *buf)
{
    int x = 0;
    int y = 0;
    
    for (; buf[x] != '\n'; x++);
    for (int j = 0; buf[j] != '\0'; j++)
        if (buf[j] == '\n')
            y++;
    if (buf[0] == 'A' && buf[x - 1] == 'A')
        return (true);
    return (false);
}

bool check_rush4(char *buf)
{
    int x = 0;
    int len = my_strlen(buf);
    
    for (; buf[x] != '\n'; x++);
    if (buf[0] == 'A' && buf[len - x - 1] == 'A')
        return (true);
    return (false);
}

bool check_rush5(char *buf)
{
    int x = 0;
    int len = my_strlen(buf);
    
    for (; buf[x] != '\n'; x++);
    if (buf[len - 2] == 'A')
        return (true);
    return (false);
}

bool check_B(char *buf, int x, int y)
{
    if (buf[0] == 'B') {
        for (int i = 3; i <= 4; i++) {
            my_putstr("[rush1-");
            my_put_nbr(i);
            my_putstr("] ");
            my_put_nbr(x);
            my_putchar(' ');
            my_put_nbr(y);
            my_putstr(" || ");
        }
        my_putstr("[rush1-5] ");
        my_put_nbr(x);
        my_putchar(' ');
        my_put_nbr(y);
        my_putchar('\n');
        return (true);
    }
    return (false);
}

void check_rush(char *buf)
{
    int x = 0;
    int y = 0;
    
    for (; buf[x] != '\n'; x++);
    for (int j = 0; buf[j] != '\0'; j++)
        if (buf[j] == '\n')
            y++;
    if (check_B(buf, x, y) == true)
        return;
    (buf[0] == 'o') ? my_putstr("[rush1-1] ") : 0;
    (buf[0] == '*' || buf[0] == '/') ? my_putstr("[rush1-2] ") : 0;
    (check_rush3(buf) == true) ? my_putstr("[rush1-3] ") : 0;
    (check_rush4(buf) == true) ? my_putstr("[rush1-4] ") : 0;
    (check_rush5(buf) == true) ? my_putstr("[rush1-5] ") : 0;
    my_put_nbr(x);
    my_putchar(' ');
    my_put_nbr(y);
    my_putchar('\n');
}
