/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** m_strlen
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}