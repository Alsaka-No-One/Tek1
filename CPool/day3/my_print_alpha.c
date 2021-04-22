/*
** EPITECH PROJECT, 2018
** my_print_alpha
** File description:
** 
*/

int my_print_alpha (void)     
{
    char letter;
    int number;

    number = 'a';
    my_putchar (number);
    letter = 98;
    while (letter != 123) {
	my_putchar (letter);
        letter = letter + 1;
    }
   
    return (0);        
}
