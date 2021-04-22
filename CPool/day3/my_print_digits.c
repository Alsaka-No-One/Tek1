/*
** EPITECH PROJECT, 2018
** my_print_digits
** File description:
**
*/

int my_print_digits (void)     
{
    char letter;
    int number;

    number = '0';
    my_putchar (number);
    letter = 061;
    while (letter != 072) {
	my_putchar (letter);
        letter = letter + 1;
    }
   
    return (0);        
}
