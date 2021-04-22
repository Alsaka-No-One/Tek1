/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** Task02
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int compt;

    compt = 0;
    while (str[compt] != '\0' ){
        my_putchar (str[compt]);
        compt =  compt + 1;
    }
}
