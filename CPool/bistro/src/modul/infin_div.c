/*
** EPITECH PROJECT, 2018
** infin_div
** File description:
** hahahahaha
*/

#include <stdio.h>
#include <stdlib.h>

char *mult(char *n1, char *n2);
char *itsmagic(char * n1, char *n2);
int my_strlen(char const *str);

int which_one_is_biggerno(char *str1, char *str2)
{
    int count1 = 0;
    int count2 = 0;

    if (my_strlen(str1) > my_strlen(str2))
        return (1);
    if (my_strlen(str1) < my_strlen(str2))
        return (2);
    while ((str1[count1] == str2[count2]) && (str1[count1] != '\0' || str2[count2] != '\0')){
            count1++;
            count2++;
    }
    if (str1[count1] > str2[count2])
        return (1);
    if (str2[count2] >= str1[count1])
        return (2);
    return (84);
}

char *itscience(char *n1, char *n2)
{
    char *n3 = "00001";
    char *one = "1";
    char *lone = "-1";
    char *result;
    int nathan = 0;
    int alain = 0;
    int nigga = 0;
    char *rn1;
    int count = 0;
    int crn1 = 0;
    int n2s = 0;

    rn1 = malloc(sizeof (char) * (my_strlen(n1)));
    while(n1[count] > '9' || n1[count] < '0')
        count++;
    while(n1[count] != '\0'){
        rn1[crn1] = n1[count];
        crn1++;
        count++;
    }
    rn1[crn1] = '\0';
    result = malloc(sizeof (char) * (my_strlen(n1)));
    if (n1[0] == '-'){
	nigga = 1;
    }
    if (n2[0] == '-'){
        n2[0] = '+';
        n2s = 1;
        if (nigga == 1)
            nigga = 0;
        else
            nigga = 1;
    }
    while (which_one_is_biggerno(mult(n2, n3), rn1) == 2)
        n3 = itsmagic(n3, one);
    n3 = itsmagic(n3, lone);
    while (n3[nathan] == '0')
        nathan++;
    if(n3[nathan] == '\0')
        result[alain] = '0';
    if (nigga == 1 && n3[nathan] != '\0'){
        result[alain] = '-';
        alain++;
    }
    while ((n3[nathan] < 10 || n3[nathan] >= 0) && n3[nathan] != '\0'){
        result[alain] = n3[nathan];
        alain++;
        nathan++;
    }
    if (n2s == 1)
		n2[0] = '-';
    return(result);
}
