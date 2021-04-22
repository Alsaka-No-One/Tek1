/*
** EPITECH PROJECT, 2018
** calcexp
** File description:
** calcul expressions
*/

#include <stdio.h>

int number(char *str, int *u, int p)
{
    int i = *u;
    long nb = 0;
    int signe = 1;

    while (((str[i] != '-') && (str[i] < '0') || (str[i] > '9') && (str[i] != '+')) && (str[i] != '\0')){
  	i++;
    }
    while (str[i] == '+' || str[i] == '-'){
        signe = str[i];
        i++;
    }
    if(signe == '-')
        signe = -1;
    else
        signe = 1;
    while (str[i] && str[i] >= '0' && str[i] <= '9'){
	nb = nb * 10 + (str[i] - 48);
	if ((signe == -1 && nb > 2147483648) || (signe == 1 && nb > 2147483647))
            return(0);
	i++;
    }
    if(p == 1)
        *u = i;
    return(nb * signe);
}

int calcexpr(char *str)
{
    int u = 0;
    int n;
    int c = 0;
    int result = 0;
    int m = 0;
        
    while(str[c] != '\0'){
        c++;
    }
    while (u < c){
        n = number(str, &u, 1);
        if(str[u] == '+' || str[u] == '-'){
            if (m == 0)
                result = result + n;
            else{
                result = result + m;
                m = 0;
            }
        }
        if(str[u] == '*'){
            if (m == 0){
                m = n * number(str, &u, 0);
            }else{
                m = m*number(str, &u, 0);
            }
        }
        if(str[u] == '/'){
            if (m == 0){
		m = n / number(str, &u, 0);                                                         
            }else{
                m = m /number(str, &u, 0);                                                         
            }
	}
        if(str[u] == '\0'){
            if (m == 0)
                result = result + n;
            else{
                result = result + m;
            }
        }
    }
    return(result);
}
