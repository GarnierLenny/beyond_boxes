/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-lenny.garnier
** File description:
** error_cases_map
*/

#include "my.h"

int error_cases_map(char **map)
{
    if (error_map_invalid_char(map) == 84 || error_map_pnb(map) == 84 ||
        error_boxes_holes(map) == 84)
        return 84;
    return 0;
}