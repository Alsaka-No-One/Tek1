/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** Task04
*/

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int pointer;
    int i2 = 0;
    
    while (str[i] != '\0') {
        i++;
        if (to_find[i2] == '\0') {
            break;
        } else if (str[i] == to_find[i2]) {
            i2++;
        } else if (str[i] != to_find[i2]) {
            pointer = i - i2;
        }
        return (0);
    }
}
