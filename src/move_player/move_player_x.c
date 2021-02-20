/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** move_player_x
*/

#include "my.h"

int move_player_right(global_t *global)
{
    if (global->map[global->player->y][global->player->x + 1] != '#') {
        if (global->map[global->player->y][global->player->x + 1] == 'X' &&
            (global->map[global->player->y][global->player->x + 2] == '#' ||
            global->map[global->player->y][global->player->x + 2] == 'X'))
            return 0;
        if (global->map[global->player->y][global->player->x + 1] == 'X') {
            global->map[global->player->y][global->player->x + 1] = ' ';
            global->map[global->player->y][global->player->x + 2] = 'X';
        }
        global->player->x += 1;
        global->moves += 1;
    }
    return 0;
}

int move_player_left(global_t *global)
{
    if (global->map[global->player->y][global->player->x - 1] != '#') {
        if (global->map[global->player->y][global->player->x - 1] == 'X' &&
            (global->map[global->player->y][global->player->x - 2] == '#' ||
            global->map[global->player->y][global->player->x - 2] == 'X'))
            return 0;
        if (global->map[global->player->y][global->player->x - 1] == 'X') {
            global->map[global->player->y][global->player->x - 1] = ' ';
            global->map[global->player->y][global->player->x - 2] = 'X';
        }
        global->player->x -= 1;
        global->moves += 1;
    }
    return 0;
}

int move_player_x(global_t *global, int c)
{
    if (c == 67)
        move_player_right(global);
    if (c == 68)
        move_player_left(global);
    return 0;
}
