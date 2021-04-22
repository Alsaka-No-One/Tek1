/*
** EPITECH PROJECT, 2018
** Match
** File description:
** project02
*/




int match(char const *s1, char const *s2)
{
    int i = 0;
    int b = 1;

    while (s1[i] != '\0'){
        while (s1[b] == s2[b]){
            b++;
            if (s1[b] == '\0' && s2[b] == '\0')
                return (1);
        }
        i++;
    }
    return (0);

}    
