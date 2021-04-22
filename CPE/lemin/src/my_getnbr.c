/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** my_get_nbr
*/

int my_getnbr_sign(char const *str, int *i)
{
    int sign = 0;

    while (str[*i] == '-' || str[*i] == '+') {
        sign = str[*i];
        (*i)++;
    }
    return (sign);
}

int my_getnbr(char const *str)
{
    int i = 0;
    long nbr_long = 0;
    int sign = 0;
    int nbr = 0;

    sign = my_getnbr_sign(str, &i);
    while (str[i] >= '0' && str[i] <= '9') {
        nbr_long = nbr_long * 10 + str[i] - 48;
        if (nbr_long < -2147483648 || nbr_long > 2147483647)
            return (-1);
        i++;
    }
    if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
        return (-1);
    if (sign == 45)
        return (-1);
    nbr = nbr_long;
    return (nbr);
}
