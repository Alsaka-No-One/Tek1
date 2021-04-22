/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** Task05
*/

int my_getnbr(char const *str)
{
    int compt = 0;
    int nbr = 0;
    long P = 1;
    int down = 0;
    
    while ((str[compt] <'0') || str[compt] > '9' && str[compt] != '\0'){
        compt ++;
    }
    compt --;
    compt = down;
    while ((str[down] <= '9') && (str[down] >= '0')){
        down --;
        compt ++;
    }
    while (compt != down){
        nbr = P * (str[compt] - 48) + nbr;
        P = P * 10;
        compt --;
    } 
    return (0);
}

