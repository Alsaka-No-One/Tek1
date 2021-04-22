/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** Task03
*/

int my_strlen(char const *str)
{
    int turn;
    int compt;

    turn = 0;
    compt = 48;
    while(str[turn] != '\0'){
        turn = turn + 1;
        compt = compt + 1;
    }
    return(compt);
}
