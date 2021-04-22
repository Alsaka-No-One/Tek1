/*
** EPITECH PROJECT, 2019
** mlib
** File description:
** Advance mis char * function
*/

static const char *DEFAULT_CMP = "0123456789abcdefghijklmnopqrstuvwxyz";

mbool mis_compatible_char(char c, char *cmp)
{
    if (!cmp)
        cmp = DEFAULT_CMP;
    if (!c)
        return (false);
    for (int i ; cmp[i] ; i++)
        if (c == cmp[i])
            return (true);
    return (false);
}

mbool mis_compatible(char *str, char *cmp)
{
    if (!cmp)
        cmp = DEFAULT_CMP;
    if (!str)
        return (false);
    for (int i = 0 ; str[i] ; i++)
        if (mis_compatible_char(str[i], cmp) == false)
            return (84);
    return (0);
}
