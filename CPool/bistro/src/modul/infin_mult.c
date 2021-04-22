/*
** EPITECH PROJECT, 2018
** Infin_add
** File description:
** Task00
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *addf(char *n1, char *n2);
int my_strlen(char const *str);

char *multc(char *n1, int n2)
{
    char *destu;
    int ln1;
    int ret = 0;
    int nn1;

    ln1 = my_strlen(n1) - 1;
    destu = malloc (sizeof(char) * (my_strlen(n1) * 4));
    if (destu == NULL)
        return (NULL);
    while (ln1 >= 0 && (n2 >= 0 && n2 < 10)){
        nn1 = n1[ln1] - 48;
        if (nn1 * n2 + ret >= 10){
            destu[ln1 + 1] = (((nn1 * n2) + ret) % 10) + 48;
            ret = (nn1 * n2 + ret) / 10;
        }
        else if (nn1 * n2 + ret < 10){
            destu[ln1 + 1] = (nn1 * n2) + ret + 48;
            ret = 0;
        }
        ln1--;
    }
    if (ret > 0)
        destu[ln1 + 1] = ret + 48;
    else
        destu[ln1 + 1] = 48;
   
    return (destu);
}

char *mult(char *n1, char *n2)
{
    int ln2 = my_strlen(n2);
    int count = ln2 - 1;
    char *multy;
    int a = 0;
    char *result;
    int nnnn = 0;
    int nega = 0;
    char *final;
    int cfin = 0;
    int cre = 0;

    if((n1[0] == '-') ^ (n2[0] == '-')){
        nega = 1;
    }
    multy = malloc (sizeof(char) * (my_strlen(n1) * my_strlen(n2) * 2));
    if (multy == NULL)
        return(NULL);
    result = malloc (sizeof(char) * (my_strlen(n1) * my_strlen(n2) * 2));
    if (result == NULL)
        return(NULL);
    final = malloc (sizeof(char) * (my_strlen(n1) * my_strlen(n2) * 2));
    if (final == NULL)
	return(NULL);
    while (count >= 0){
        multy = multc(n1, n2[count] - 48);
        while(nnnn < a){
            multy[my_strlen(multy)] = '0';
            nnnn++;
        }
        result = addf(multy, result);
        count--;
        a++;
        nnnn = 0;
    }
    if (nega == 1){
        final[cfin] = '-';
        cfin++;
    }
    while(result[cre] != '\0'){
        final[cfin] = result[cre];
        cre++;
        cfin++;
    }
    free(multy);
    free(result);
    return(final);
}
