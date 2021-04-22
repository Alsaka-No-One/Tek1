/*
** EPITECH PROJECT, 2019
** solostumper2
** File description:
** The main function
*/

#include "palindrome.h"

int check_the_arg(char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        if ((src[i] >= 'A' && src[i] <= 'Z')
            || (src[i] >= 'a' && src[i] <= 'z'))
            i++;
        else {
            write(2, "This is not a word!\n", 20);
            return (84);
        }
    }
    return (0);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

void compare_words(char *str, char *check)
{
    int i = my_strlen(str);

    while (i != 0) {
        if (str[i] == check[i] || str[i] == check[i] - 32
            || str[i] == check[i] + 32)
            i--;
        else {
            write(1, "not a palindrome.\n", 18);
            return;
        }
    }
    if (i == 0)
        write(1, "palindrome!\n", 12);
}

void palindrome_main(char *str)
{
    int i = 0;
    int ii = 0;
    int j = 0;
    char new_str[my_strlen(str) + 1];

    while (str[i] != '\0')
        i++;
    i = i - 1;
    ii = i;
    while (j <= ii) {
        new_str[j] = str[i];
        j++;
        i--;
    }
    new_str[j] = '\0';
    compare_words(str, new_str);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        write(2, "Error: missing arguments.\n", 26);
        return (84);
    }
    else {
        if (check_the_arg(argv[1]) == 84)
            return (84);
        palindrome_main(argv[1]);
    }
    return (0);
}
