/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-lenny.garnier
** File description:
** error_boxes_holes
*/

#include "my.h"

int error_boxes_holes(char **map)
{
    int i = 0;
    int y = 0;
    int boxes = 0;
    int holes = 0;

    for (; map[y] != NULL; y++) {
        for (i = 0; map[y][i] != '\0'; i++) {
            if (map[y][i] == 'X')
                boxes++;
            if (map[y][i] == 'O')
                holes++;
        }
    }
    if (holes == 0 || boxes == 0 || (boxes != holes))
        return 84;
    return 0;
}