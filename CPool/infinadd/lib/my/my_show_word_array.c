/*
** EPITECH PROJECT, 2018
** my_show_word_array
** File description:
** task03
*/

void my_putchar(char c);
void my_putstr(char *str);

int my_show_word_array(char *const *tab)
{
    int i = 0;

    while (tab[i] != '\0'){
        my_putstr (tab[i]);
        my_putchar ('\n');
        i++;
    }
}
