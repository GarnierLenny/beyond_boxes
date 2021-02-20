/*
** EPITECH PROJECT, 2021
** bonus_v2
** File description:
** load_map_misc
*/

#include "my.h"

int find_p(char **map, int option)
{
    int y = 0;
    int i = 0;

    for (; map[y] != NULL; y++) {
        for (i = 0; map[y][i] != '\0'; i++) {
            if (map[y][i] == 'P') {
                if (option == 0)
                    return i;
                return y;
            }
        }
    }
    return 0;
}

char **keep_holes(global_t *global)
{
    int i = 0;
    int j = 0;

    global->holes = cpy_ss(global->map);
    for (; global->holes[j] != NULL; j++) {
        for (i = 0; global->holes[j][i] != '\0'; i++) {
            if (global->holes[j][i] != 'O' && global->holes[j][i] != 'V')
                global->holes[j][i] = ' ';
        }
    }
    return global->holes;
}

int find_holes_nb(char **map)
{
    int i = 0;
    int j = 0;
    int count = 0;

    for (; map[j] != NULL; j++) {
        for (i = 0; map[j][i] != '\0'; i++) {
            if (map[j][i] == 'O' || map[j][i] == 'V')
                count++;
        }
    }
    return count;
}

int find_map_line_nb(char **map)
{
    int i = 0;

    for (; map[i] != NULL ; i++);
    return i;
}

int find_map_col_nb(char **map)
{
    int lines = 0;
    int i = 0;
    int max = 0;

    for (; map[lines] != NULL; lines++) {
        for (i = 0; map[lines][i] != '\0'; i++)
            if (i > max)
                max = i;
    }
    return max;
}