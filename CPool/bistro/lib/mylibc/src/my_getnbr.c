/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** task05
*/

int isneg(char const *str)
{
    int neg = 0;

    for (int a = 0 ; str[a] != '\0' ; a += 1){
        if ( str[a] < '0' || str[a] > '9' ){
            if ( str[a] == '-' ){
                neg += 1;
            }
        } else {
            if ( str[a] < '0' || str[a] > '9' )
                break;
        }
    }
    neg = neg % 2;
    return (neg);
}

int get_only_nbr(char const *str)
{
    int b = 0;
    int c = 0;

    for (int a = 0 ; str[a] != '\0' ; a += 1){
        if ( str[a] >= '0' && str[a] <= '9'){
            b *= 10;
            b += (str[a] - 48);
            c = c + 1;
        } else if ( c > 0 ) {
            break;
        }
    }
    return (b);
}

int is_toobig(char const *str)
{
    int b = 0;
    int c = 0;
    int d;

    for (int a = 0 ; str[a] != '\0' ; a += 1){
        if ( str[a] >= '0' && str[a] <= '9'){
            b *= 10;
            b += (str[a] - 48);
            c = c + 1;
        }if (b < 0){
            return (1);
        }
    }
}

int my_getnbr(char const *str)
{
    int neg = isneg(str);
    int nbr = get_only_nbr(str);
    int toobig = is_toobig(str);

    if (nbr == 2147483647){
        return (2147483647);
    }
    if (nbr * -1 == -2147483648 ){
        return (-2147483648);
    }
    if (!(toobig == 1 )){
        if ( neg == 1 ){
            return (nbr * -1);
        } else if ( neg == 0 ){
            return (nbr);
        } else
            return (0);
    } else
        return (0);
}
