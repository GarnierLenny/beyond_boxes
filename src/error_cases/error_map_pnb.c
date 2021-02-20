/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-lenny.garnier
** File description:
** error_map_pnb
*/

#include "my.h"

int error_map_pnb(char **map)
{
    int i = 0;
    int y = 0;
    int count = 0;

    for (; map[y] != NULL; y++) {
        for (i = 0; map[y][i] != '\0'; i++) {
            if (map[y][i] == 'P')
                count++;
        }
    }
    if (count != 1)
        return 84;
    return 0;
}