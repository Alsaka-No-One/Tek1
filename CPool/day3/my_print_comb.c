/*
** EPITECH PROJECT, 2018
** my_print_comb
** File description:
** 
*/

int my_print_comb(void)
{
    int number;
    int midnumber;
    int lastnumber;
    int coma;
    int space;

    coma = ',';
    space = ' ';
    for(number = '0'; number <= '7'; number ++){
        for(midnumber = '1'; midnumber <= '8'; midnumber ++){
            for(lastnumber = '2'; lastnumber <= '9'; lastnumber ++){
                my_putchar(number);
                my_putchar(midnumber);
                my_putchar(lastnumber);
                my_putchar(coma);
                my_putchar(space); 
            }
        }
    }
    return(0);
}
