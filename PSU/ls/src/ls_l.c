/*
** EPITECH PROJECT, 2019
** PSU my_ls | ls -l
** File description:
** The function to have the '-l' option
*/

#include "ls.h"

void disp_rights(mode_t rt)
{

    my_putchar((rt & S_IFDIR) ? 'd' : '-');
    my_putchar((rt & S_IRUSR) ? 'r' : '-');
    my_putchar((rt & S_IWUSR) ? 'w' : '-');
    my_putchar((rt & S_IXUSR) ? 'x' : '-');
    my_putchar((rt & S_IRGRP) ? 'r' : '-');
    my_putchar((rt & S_IWGRP) ? 'w' : '-');
    my_putchar((rt & S_IXGRP) ? 'x' : '-');
    my_putchar((rt & S_IROTH) ? 'r' : '-');
    my_putchar((rt & S_IWOTH) ? 'w' : '-');
    my_putchar((rt & S_IXOTH) ? 'x' : '-');
    my_printf(" ");
}

void print_name_grp(struct stat rt)
{
    struct group *grp = NULL;
    struct passwd *name = NULL;

    if ((name = malloc(sizeof(struct passwd) * 1)) == NULL)
        return;
    if ((grp = malloc(sizeof(struct group) * 1)) == NULL)
        return;
    name = getpwuid(rt.st_uid);
    grp = getgrgid(rt.st_gid);
    my_printf("%s ", name->pw_name);
    my_printf("%s ", grp->gr_name);
}

char *get_time(time_t *date)
{
    char *new_date = NULL;
    char *wrong_date = ctime(date);
    int i = 0;

    new_date = malloc(sizeof(char) * 14);
    while (i != 13) {
        new_date[i] = wrong_date[i + 3];
        i++;
    }
    new_date[i] = '\0';
    return (new_date);
}

int get_total(void)
{
    DIR *rep = NULL;
    struct dirent *rd = NULL;
    struct stat rt;
    int result = 0;

    if ((rep = opendir("./")) == NULL)
        exit(84);
    while ((rd = readdir(rep)) != NULL)
        if (rd->d_name[0] != '.') {
            ((stat(rd->d_name, &rt)) == -1) ? exit(84) : 0;
            result += rt.st_blocks;
        }
    result /= 2;
    return (result);
}

void ls_l(void)
{
    struct stat rt;
    struct dirent *rd = NULL;
    DIR *rep = NULL;

    my_printf("total %d\n", get_total());
    if ((rep = opendir("./")) == NULL)
        exit(84);
    while ((rd = readdir(rep)) != NULL)
        if (rd->d_name[0] != '.') {
            ((stat(rd->d_name, &rt)) == -1) ? exit(84) : 0;
            disp_rights(rt.st_mode);
            my_printf("%d ", rt.st_nlink);
            print_name_grp(rt);
            my_printf("%d\t", rt.st_size);
            my_printf("%s ", get_time(&rt.st_mtime));
            color_the_name(rd->d_name, rt.st_mode);
        }
}