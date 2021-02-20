/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-lenny.garnier
** File description:
** check_box_movements
*/

#include "my.h"

int is_char_block(char c)
{
    if (c == '#' || c == 'X')
        return 1;
    return 0;
}

int check_one_box_mov(char **map, int y, int x)
{
    if (is_char_block(map[y - 1][x]) == 1 && is_char_block(map[y][x - 1]) == 1)
        return 1;
    if (is_char_block(map[y - 1][x]) == 1 && is_char_block(map[y][x + 1]) == 1)
        return 1;
    if (is_char_block(map[y + 1][x]) == 1 && is_char_block(map[y][x + 1]) == 1)
        return 1;
    if (is_char_block(map[y + 1][x]) == 1 && is_char_block(map[y][x - 1]) == 1)
        return 1;
    return 0;
}

int check_boxes_movements(char **map)
{
    int i = 0;
    int j = 0;

    for (; map[j] != NULL; j++) {
        for (i = 0; map[j][i] != '\0'; i++) {
            if (map[j][i] == 'X') {
                if (check_one_box_mov(map, j, i) != 1)
                    return 0;
            }
        }
    }
    return 1;
}