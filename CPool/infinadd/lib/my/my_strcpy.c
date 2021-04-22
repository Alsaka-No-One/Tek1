/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** Task01
*/

char *my_strcpy(char *dest, char const *scr)
{
    int i = 0;
    
    while (scr[i] != '\0'){
        dest[i] = scr[i];
        i ++;
    }
    dest[i] = '\0';
    return (dest);    
}
