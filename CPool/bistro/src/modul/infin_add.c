/*
** EPITECH PROJECT, 2018
** Infin_add
** File description:
** Task00
*/

#include <stdlib.h>
#include <unistd.h>

int which_one_is_bigger2(char *str1, char *str2)
{
    int count1 = 0;
    int count2 = 0;
    
    if(str1[count1] == '-')
        count1++;
    if(str2[count2] == '-')
        count2++;
    while(str1[count1] != '\0'|| str2[count2] != '\0'){
        if(str1[count1] == str2[count2]){
            count1++;
            count2++;
        }
        if(str1[count1] > str2[count2])
            return(1);
        if(str2[count2] > str1[count1])
            return(2);
    }
    return (84);
}

int counter2(char *nb)
{
    int i = 0;
    
    while ( nb[i] != '\0'){
        i ++;
    }
    return(i);
}

int add2(int n1, int n2, int *ret, int signe1, int signe2, int *sret, int sous)
{
    int d3;
    int d1 = n1 - 48;
    int d2 = n2 - 48;
    int lret = *ret;
    int sousret = *sret;
    
    if (d1 < 0 || d2 > 9){
        d1 = 0;
    }
    if (d2 <0 || d2 > 9){
        d2 = 0;
    }
    if (signe1 == 1){
        d1 = d1 * (-1);
    }
    if (signe2 == 1){
        d2 = d2 * (-1);
    }
    if (sous == 1){
        d1 = d1 * (-1);
        d2 = d2 * (-1);
    }
    if(((d1 + d2 + lret - sousret) < 10) && ((d1 + d2 + lret - sousret) >= 0)){
        d3 = d1 + d2 + lret - sousret;
        *ret = 0;
        *sret = 0;
    }
    else if((d1 + d2 + lret - sousret) < 0){
        d3 = 10 + (d1 + d2 - sousret);
	*sret = 1;
    }            
    else if((d1 + d2 + lret - sousret) >= 10){
        d3 = (d1 + d2 + lret) - 10;
        *ret = 1;
    }
    return(d3);
}

char *addf(char *n1, char *n2)
{
    int nd1;
    int nd2;
    int ndm;
    char *dest;
    int ret = 0;
    int sret = 0;
    int signe1 = 0;
    int signe2 = 0;
    int sous = 0;
    char *result;
    int nathan = 0;
    int alain = 0;

    nd1 = counter2(n1) - 1;
    nd2 = counter2(n2) - 1;
    if (nd1 <= nd2){
        ndm = nd2 + 1;
    }
    else{
        ndm = nd1 + 1;
        }
    dest = malloc (sizeof(char) * (ndm + 2));
    if (dest == NULL)
	return (0);
    result = malloc (sizeof(char) * (ndm + 3));
    if (dest == NULL)
        return (0);
    if (n1[0] == '-'){
        if (nd1 > nd2 + 1){
            sous = 1;
        }
        if((nd1 == nd2 + 1) && (which_one_is_bigger2(n1, n2) == 1))
            sous = 1;
        signe1 = 1;
    }
    if (n2[0] == '-'){
        if (nd2 > nd1 + 1){
            sous = 1;
        }
        if((nd1 == nd2 - 1) && (which_one_is_bigger2(n1, n2) == 2)){
            sous = 1;
	}
        signe2 = 1;
    }
    while(ndm >= 0){
        dest[ndm] = add2(n1[nd1], n2[nd2], &ret, signe1, signe2, &sret, sous);
        dest[ndm] = dest[ndm] + 48;
        ndm--;
        if(nd1 >= 0){
            nd1--;
        }
        if(nd2 >= 0){
            nd2--;
        }
    }
    while (dest[nathan] == '0')
        nathan++;
    if(dest[nathan] == '\0')
        result[alain] = '0';
    if (sous == 1 && dest[nathan] != '\0'){
        result[alain] = '-';
        alain++;
    }
    while ((dest[nathan] < 10 || dest[nathan] >= 0) && dest[nathan] != '\0'){
        result[alain] = dest[nathan];
        alain++;
        nathan++;
    }
    return(result);
}                                                                                        


