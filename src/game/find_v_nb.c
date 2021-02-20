/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-lenny.garnier
** File description:
** find_v_nb
*/

#include "my.h"

int find_v_nb(char **holes)
{
    int i = 0;
    int y = 0;
    int count = 0;

    for (; holes[y] != NULL; y++) {
        for (i = 0; holes[y][i]; i++) {
            if (holes[y][i] == 'V')
                count++;
        }
    }
    return count;
}