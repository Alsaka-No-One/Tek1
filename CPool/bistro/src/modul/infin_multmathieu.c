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

char *multmath1(char *n1, char *n2)
{
    int nigga = 0;
    int count = 0;
    int n;
    int a = 1;
    char *result;
    char *dest;
    int nathan = 0;
    int alain = 0;
    int n1s = 0;
    int n2s = 0;
    
    result = malloc(sizeof (char) * (my_strlen(n1) * my_strlen(n2)+ 1));
    dest = malloc(sizeof (char) * (my_strlen(n1) * my_strlen(n2) + 1));
    if (n1[0] == '-'){
        n1[0] = '+';
        nigga = 1;
        n1s = 1;
    }
    if (n2[0] == '-'){
        n2[0] = '+';
        n2s = 1;
        if (nigga == 1)
            nigga = 0;
        else
            nigga = 1;
    }
    while (n2[count] != '\0')
        count++;
    count--;
    while (n2[count] != '\0'){
        n = (n2[count] - 48) * a;
        while (n > 0){
            result = itsmagic(result, n1);
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
    if (n1s == 1)
		n1[0] = '-';
	if (n2s == 1)
		n2[0] = '-';
    return (dest);
}
