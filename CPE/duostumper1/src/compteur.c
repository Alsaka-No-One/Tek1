/*
** EPITECH PROJECT, 2019
** fractals
** File description:
** number charact
*/

int compteur_charact(char **av)
{
    int i = 0;

    while (av[2][i] != '@')
        i++;
    return (i);
}
