/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** copy_rotate
*/

char *copy_rotate(char **map, char *dest, int end_map, int col)
{
    int i = 0;

    for ( ; end_map >= 0; end_map--, i++)
        dest[i] = map[end_map][col];
    dest[i] = '\0';
    return (dest);
}
