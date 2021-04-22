/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** Task3
*/

char *my_revstr(char *str)
{ 
    int beg = 0;
    int end = 0;  
    int r;
    
    while (str[end] != '\0'){
        end++;
    }
    end--;
    while (end >= beg){
        r = str[end];
        str[end] = str [beg];
        str [beg] = r;
        end--;
        beg++;
    }
    return(str);
}
