/*
** EPITECH PROJECT, 2018
** my_swap
** File description:
** Swap
*/

void my_swap(int *a, int *b)
{
    int try;
    try = *a;
    *a = *b;
    *b = try;    
}
