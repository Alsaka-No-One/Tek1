/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** unsetenv
*/

#include "shell.h"

// static char **my_unsetenv(char ***envp, int i)
// {
//     char **new_env = NULL;
//     int j = 0;

//     printf("je suis rentré ici\n");
//     printf("%d\n", i);
//     if ((new_env = malloc(sizeof(char *)
            //  * (compt_array(*envp) + 1))) == NULL)
//         return (NULL);
//     for (; (*envp)[j] != NULL; j++) {
//         if (j == i && (*envp)[j + 1] != NULL)
//             j++;
//         else if (j == i && (*envp)[j + 1] == NULL) {
//             new_env[j] = NULL;
//             return (new_env);
//         }
//         new_env[j] = malloc(sizeof(char) * (my_strlen((*envp)[j]) + 1));
//         if (new_env[j] == NULL)
//             return (NULL);
//         new_env[j] = my_strcpy(new_env[j], (*envp)[j]);
//     }
//     new_env[j] = NULL;
//     // for (int k = 0; new_env[k] != NULL; k++)
//     //     printf("%s\n", new_env[k]);
//     return (new_env);
// }

// static int check_unset(char **arg, char ***envp, int i)
// {
//     for (int j = 0; (*envp)[j] != NULL; j++) {
//         if (my_strcomp_env(arg[i], (*envp)[j]) == 1)
//             *envp = my_unsetenv(envp, j);
//     }
//     if (*envp == NULL)
//         return (ERROR);
//     return (SUCCESS);
// }

// int make_unsetenv(char **arg, char ***envp)
// {
//     if (compt_array(arg) == 1) {
//         my_putstr("unsetenv: Too few arguments.\n");
//         return (ERROR);
//     }
//     for (int i = 0; arg[i] != NULL; i++)
//         if (check_unset(arg, envp, i) == ERROR)
//             return (ERROR);
//     return (SUCCESS);
// }

int make_unsetenv(char **arg, char ***envp)
{
    if (compt_array(arg) == 1) {
        my_putstr("unsetenv: Too few arguments.\n");
        return (ERROR);
    }
    (void)envp;
    my_putstr("unsetenv c'est moi!\n");
    return (SUCCESS);
}