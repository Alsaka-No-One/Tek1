/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2018
** File description:
** str_cmp
*/

int str_compare(char const *str1, char const *str2)
{
    int i = 0;
    int i2 = 0;

    for (i = 0 ; str1[i] != '\0' && str2[i2] != '\0' ; i += 1) {
        if ((str1[i] != str2[i2]) && str2[i2] != '*')
            return (-1);
        if (str2[i2] != '*')
            i2 += 1;
    }
    if (str2[i2] == '*')
            i2 += 1;
    if (str1[i] == '\0' && str2[i2] == '\0')
        return (0);
    return (-1);
}

int compare_var(char *str1, char *str2)
{
    int i = 0;

    for ( ; str1[i] != '\0' && str1[i] != '=' && str2[i] != '\0' ; i += 1)
        if (str1[i] != str2[i])
            return (-1);
    if (str1[i] == '=' && str2[i] == '\0')
        return (0);
    return (-1);
}