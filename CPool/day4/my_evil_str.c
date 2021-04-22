/*
** EPITECH PROJECT, 2018
** my_evil_str
** File description:
** Task02
*/

char *my_evil_str(char *str)
{ 
    int beg = 0;
    int end = 0;  
    int r;

    while (str[end] != '\0'){
        end = end + 1;
    }
    end = end - 1;
    while (beg <= end){
        r = str[beg];
        str[beg] = str [end];
        str [end] = r;
        beg = beg + 1;
        end = end - 1;                
    }
    return(str);
}

