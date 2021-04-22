/*
** EPITECH PROJECT, 2019
** mlib
** File description:
** String comparator
*/

typedef enum mbool_e {
    true = 1,
    false = 0
} mbool;

//strl: long string
//strs: short string
int mstrcmpltn(char *strl, char *strs)
{
    int i = 0;

    if (!strl || !strs)
        return (false);
    for ( ; strl[i] && strs[i] && strl[i] == strs[i] ; i++);
    if(!strl[i] && !strs[i])
        return (true);
    if (!strl[i])
        return (false);
    if (!strs[i])
        return (true);
    return (false);
}

int mstrcmp(char *str1, char *str2)
{
    int i = 0;

    if (!str1 || !str2)
        return (0);
    for ( ; str1[i] && str2[i] && str1[i] == str2[i] ; i++);
    if (!str1[i] && !str2[i])
        return (0);
    if (!str1[i] || str1[i] < str2[i])
        return (-1);
    if (!str2[i] || str2[i] < str1[i])
        return (1);
    return (0);
}

mbool mstrsame(char *str1, char *str2)
{
    int i = 0;

    if (!str1 || !str2)
        return (false);
    for ( ; str1[i] && str2[i] ; i++)
        if (str1[i] != str2[i])
            return (false);
    if (!str1[i] && !str2[i])
        return (true);
    if (!str1[i] || !str2[i])
        return (false);
    if (str1[i] != str2[i])
        return (false);
    return (true);
}
