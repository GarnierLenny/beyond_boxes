/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** disp_map
*/

#include "my.h"

void disp_map_n(char **map)
{
    int i = 0;
    int y = 0;

    for (; map[i] != NULL; i++, y++) {
        mvprintw(y, 0, map[i]);
    }
    refresh();
}