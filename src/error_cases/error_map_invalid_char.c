/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-lenny.garnier
** File description:
** error_map_invalid_char
*/

#include "my.h"

int is_char_correct(char c)
{
    if (c == ' ' || c == '\n' || c == '#' || c == 'X' || c == 'O' || c == 'P'
        || c == '\0')
        return 1;
    return 0;
}

int error_map_invalid_char(char **map)
{
    int i = 0;
    int y = 0;

    for (; map[y] != NULL; y++) {
        for (i = 0; map[y][i] != '\0'; i++) {
            if (is_char_correct(map[y][i]) == 0)
                return 84;
        }
    }
    return 0;
}