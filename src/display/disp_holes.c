/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-lenny.garnier
** File description:
** disp_holes
*/

#include "my.h"

char **disp_holes(char **map, char **holes)
{
    int i = 0;
    int y = 1;

    for (; holes[y + 1] != NULL; y++) {
        for (i = 0; holes[y][i + 1] != '\0'; i++) {
            if (holes[y][i] == 'O' || holes[y][i] == 'V') {
                if ((map[y][i] == 'X' && holes[y][i] == 'O') ||
                    (map[y][i] == 'X' && holes[y][i] == 'V'))
                    holes[y][i] = 'V';
                else
                    holes[y][i] = 'O';
                mvprintw(y, i, char_to_str(holes[y][i]));
            }
        }
    }
    return holes;
}