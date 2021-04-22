/*
** EPITECH PROJECT, 2018
** Inf_multnathan
** File description:
** c'est trop bien !
*/

#include <stdio.h>
#include <stdlib.h>

char *itsmagic(char *n1, char *n2);

int my_strlen(char const *str)
{
    int turn;
    int compt;

    turn = 0;
    while (str[turn] != '\0'){
        turn = turn + 1;
    }
    return (turn);
}

int main(int ac, char **av)
{
    int nigga = 0;
    int count = 0;
    int n;
    int a = 1;
    char *result;
    char *dest;
    int nathan = 0;
    int alain = 0;
    
    result = malloc(sizeof(char) * (my_strlen(av[1]) * my_strlen(av[2])+ 1));
    dest = malloc(sizeof(char) * (my_strlen(av[1]) * my_strlen(av[2]) + 1));
    if (av[1][0] == '-'){
        av[1][0] = '+';
        nigga = 1;
    }
    if (av[2][0] == '-'){
        av[2][0] = '+';
        if (nigga == 1)
            nigga = 0;
        else
            nigga = 1;
    }
    while(av[2][count] != '\0')
        count++;
    count--;
    while(av[2][count] != '\0'){
        n = (av[2][count] - 48) * a;
        while(n > 0){
            result = itsmagic(result, av[1]);
            n--;
        }
        a = a * 10;
        count--;
    }
    if (nigga == 1){
        dest[alain] = '-';
        alain++;
            }
    while (result[nathan] == '0')
            nathan++;
    while ((result[nathan] < 10 || result[nathan] >= 0) && result[nathan] != '\0'){
            dest[alain] = result[nathan];
            alain++;
            nathan++;
        }    
    printf("%s", dest);
}
