/*
** EPITECH PROJECT, 2018
** rush1-5
** File description:
** rush1-5
*/

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
    int l;
    
    if ((x <= 0) || (y <= 0)){
        while (error[count] != '\0'){ 
            my_putchar(error[count]);
            count ++;
        }
        return (0);
    }
    if (x == 1){
        for (l = 1; l <= y; l++){
            my_putchar ('B');
            my_putchar ('\n');
        }
        return (0);
    }
    if (y == 1){
        for (l = 1; l <= x; l++){
            my_putchar ('B');
        }
        return (0);
    }
    if ((x == 1) && (y == 1)){
        my_putchar ('B');
        return (0);
    }
    my_putchar ('A');
    for (j = 1; j <= x2; j++){  
        my_putchar ('B');
    }
    if (j = x - 1){    
        my_putchar ('C' );
    }
    for (i = 1; i <= y2; i++){ 
        my_putchar ('\n');
        my_putchar ('B');
        for (p = 1; p <= x2; p++){
            my_putchar (' ');
        }
        my_putchar ('B');
    }
    if (i = y - 1){    
        my_putchar ('\n');
        my_putchar ('C');
    }
    for (k = 1; k<= x2; k++){
        my_putchar('B');
    }
    if (k = x - 1){
        my_putchar('A');
    }
}

