/*
** EPITECH PROJECT, 2018
** my_str_isnum.c
** File description:
** my_str_isnum
*/

int my_str_isnum(char const *str)
{
    int x = 1;

    if (str[0] < '0' || str[0] > '9') {
        if (!(str[0] == '-' && str[1] != '\0'))
            return (0);
    }
    for (int i = 1; str[i] != '\0' && str[i] != '\n'; i++) {
        x = 0;
        if (str[i] < '0' || str[i] > '9')
            return (x);
        x = 1;
    }
    return (x);
}
