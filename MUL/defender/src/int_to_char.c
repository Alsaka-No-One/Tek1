/*
** EPITECH PROJECT, 2019
** *
** File description:
** int_to_char
*/

#include "my_defender.h"

static int conversion(int rest)
{
    if (rest >= 0 && rest <= 9)
        rest += 48;
    return (rest);
}

static int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

static char *my_revstr(char *str)
{
    char *dest = malloc(sizeof(char) * my_strlen(str));
    int i = 0;
    int j = 0;

    while (str[i] != '\0')
        i++;
    i--;
    while (i >= 0) {
        dest[j] = str[i];
        j += 1;
        i -= 1;
    }
    dest[j] = '\0';
    return (dest);
}

static void draw_text(sfText *text, char *str, game_t *game)
{
    sfText_setString(text, str);
    sfRenderWindow_drawText(game->window, text, NULL);
    free(str);
}

void int_to_char(int nb, sfText *text, game_t *game)
{
    char *str = malloc(sizeof(char) * 11);
    int i = 0;
    int rest = 0;
    int status = 0;

    if (nb == 0) {
        str[0] = '0';
        str[1] = '\0';
    }
    while (nb > 0) {
        rest = nb % 10;
        nb = nb / 10;
        rest = conversion(rest);
        str[i] = rest;
        i++;
    }
    if (i != 0)
        str[i] = '\0';
    str = my_revstr(str);
    draw_text(text, str, game);
}