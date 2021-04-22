/*
** EPITECH PROJECT, 2018
** rush1-1
** File description:
** rush1-1
*/

void my_putchar (char c)
{
    write (1, &c, 1);
}

void rush(int x, int y)
{
    int i;
    int y2 = y - 2;
    int j;
    int x2 = x - 2;
    int k;
    int p;
    char error[] = "Invalid size\n";
    int count = 0;
    
    if ((x <= 0) || (y <= 0)){
        while (error[count] != '\0'){ 
            my_putchar(error[count]);
            count ++;
        }
        return (0);
    }
    my_putchar('o'); 
    for (j = 1; j <= x2; j++){  
        my_putchar ('-');
    }
    if (j = x - 1){    
        my_putchar ('o');
    }
    for (i = 1; i <= y2; i++){ 
        my_putchar ('\n');
        my_putchar ('|');
        for (p = 1; p <= x2; p++){
            my_putchar (' ');
        }
        my_putchar ('|');
    }
    if (i = y - 1){    
        my_putchar ('\n');
        my_putchar ('o');
    }
    for (k = 1; k<= x2; k++){
        my_putchar('-');
    }
    if (k = x - 1){
        my_putchar('o');
    }
}

int main()
{
    rush (4, 17);
    return (0);
}
