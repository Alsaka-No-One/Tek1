/*
** EPITECH PROJECT, 2018
** Step1
** File description:
** Step1
*/

int counting_nbr_let(int ac, char **av)
{
    int turn = 0;
    int i = 0;
    int b = 0;
    int nb = 2;

    while (nb != ac){
        while (av[1][turn] != '\0'){
            if (av[1][turn] == av[nb][0])
                i++;
            if (av[1][turn] == av[nb][0] + 32 || av[1][turn] == av[nb][0] - 32)
                b++;
            turn++;
        }
        if (av[nb][0] == 'A')
            i--;
        i = i + b;
        my_putchar (av[nb][0]);
        my_putchar (':');
        my_putchar (i + 48);
        my_putchar ('\n');
        nb++;
    }
}
