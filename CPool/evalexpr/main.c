#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int calcexpr(char *str);

int my_putint(int nb, int *countf, char *final);

int my_put_nbr(int nb);

int backpar(char const *str, int countback)
{
    int end = countback;
    int count = 0;
    int i = 0;
    int n;
    char *dest;

    dest = malloc(sizeof(char) * 100);
    
    while(str[countback] != '(')
        countback--;
    countback++;
    while(countback != end){
        dest[count] = str[countback];
        countback++;
        count++;
    }
    n = calcexpr(dest);
    return(n);
}


int eval(char const *str)
{
    int count = 0;
    int countback;
    int endpar = 0;
    int n;
    char *final;
    int countf = 0;
    int result;

    final = malloc(sizeof(char) * 100000);
    while(str[count] != '\0'){
        if(str[count] == '('){
            while(str[count] != ')')
                count++;
            if(str[count] == ')'){
                n = backpar(str, count); 
                my_putint(n, &countf, final);
                count++;
            }
        }
        final[countf] = str[count];
        countf++;
        count++;
    }
    result = calcexpr(final);
    return(result);
}

int comptpar(char const *str)
{
    int count = 0;
    int countp = 0;

    while(str[count] != '\0'){
	if(str[count] == '(')
            countp++;
        count++;
    }
    return(countp);
}

int main(int ac, char **av)
{
    int n;
    if (ac == 2){
        n = eval(av[1]);
        my_put_nbr(n);
        return(0);
    }
    return(84);
}
