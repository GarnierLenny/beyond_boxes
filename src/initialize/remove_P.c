/*
** EPITECH PROJECT, 2021
** bonus_v2
** File description:
** remove_P
*/

#include "my.h"

char **remove_P(char **map)
{
    int i = 0;
    int j = 0;

    for (; map[j] != NULL; j++) {
        for (i = 0; map[j][i] != '\0'; i++) {
            if (map[j][i] == 'P') {
                map[j][i] = ' ';
            }
        }
    }
    return map;
}