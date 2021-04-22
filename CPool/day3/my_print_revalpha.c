/*
** EPITECH PROJECT, 2018
** my_print_revalpha
** File description:
**
*/

int my_print_revalpha (void)     
{
    char letter;
    int number;

    number = 'z';
    my_putchar (number);
    letter = 121;
    while (letter != 96) {
	my_putchar (letter);
        letter = letter - 1;
    }
   
    return (0);        
}

