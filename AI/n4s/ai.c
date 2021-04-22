/*
** EPITECH PROJECT, 2019
** AIA_n4s_2018
** File description:
** ia
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int nxtnbr(char *str, int *u);

char *get_line(void);

int *tableau(void);

float get_lil(int *tab);

int magic(int *tab);

int cleared(void)
{
    char *line;
    int i = 0;
    int u = 0;
    int ret = 1;
    char *comp = "Track Cleared";

    fprintf(stdout, "get_info_simtime\n");
    line = get_line();

    for (; line[i] != '\0'; i++)
        (line[i] == comp[u]) ?  u++ : 0;
    (u >= 12) ? ret = 0 : 0;
    return (ret);
}

int choose_dir(int *tab, float dir, int pos)
{
    if (tab[pos] < 500) {
        dir = pos + 1;
        if (dir < 17) {
            dir = dir / 16;
            printf((tab[pos] < 200) ?
                "WHEELS_DIR:-0.515\n" : "WHEELS_DIR:-0.315\n");
            get_line();
        }
        if (dir > 17) {
            dir = (dir -17)/ 16 * -1 ;
            printf((tab[pos] < 200) ?
                "WHEELS_DIR:0.515\n" : "WHEELS_DIR:0.315\n");
            get_line();
        }
    }
    else {
        printf("WHEELS_DIR:0\n");
        get_line();
    }
    return (dir);
}

int acceleration(int *tab)
{
    int pos = get_lil(tab);

    if (magic(tab) == 0) {
        fprintf(stdout, "car_forward:1\n");
        get_line();
    }
    else {
        fprintf(stdout, "car_forward:0.3\n");
        get_line();
    }
    return (pos);
}

void ai(void)
{
    int *tab;
    float dir = 0;
    int pos = 0;

    while (1) {
        tab = tableau();
        if (tab[16] < 50) {
            fprintf(stdout, "car_backwardS:1\n");
            get_line();
            break;
        }
        pos = acceleration(tab);
        dir = choose_dir(tab, dir, pos);
        if (cleared() == 0)
            break;
    }
}

int main(void)
{
    setbuf(stdout, NULL);
    fprintf(stdout, "start_simulation\n");
    get_line();
    fprintf(stdout, "car_forward:0.3\n");
    get_line();
    ai();
    fprintf(stdout, "STOP_SIMULATION\n");
}