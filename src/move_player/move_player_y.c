/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** move_player_y
*/

#include "my.h"

int move_player_up(global_t *global)
{
    if (global->map[global->player->y - 1][global->player->x] != '#') {
        if (global->map[global->player->y - 1][global->player->x] == 'X' &&
            (global->map[global->player->y - 2][global->player->x] == '#' ||
            global->map[global->player->y - 2][global->player->x] == 'X'))
            return 0;
        if (global->map[global->player->y - 1][global->player->x] == 'X') {
            global->map[global->player->y - 1][global->player->x] = ' ';
            global->map[global->player->y - 2][global->player->x] = 'X';
        }
        global->player->y -= 1;
        global->moves += 1;
    }
    return 0;
}

int move_player_down(global_t *global)
{
    if (global->map[global->player->y + 1][global->player->x] != '#') {
        if (global->map[global->player->y + 1][global->player->x] == 'X' &&
            (global->map[global->player->y + 2][global->player->x] == '#' ||
            global->map[global->player->y + 2][global->player->x] == 'X'))
            return 0;
        if (global->map[global->player->y + 1][global->player->x] == 'X') {
            global->map[global->player->y + 1][global->player->x] = ' ';
            global->map[global->player->y + 2][global->player->x] = 'X';
        }
        global->player->y += 1;
        global->moves += 1;
    }
    return 0;
}

int move_player_y(global_t *global, int c)
{
    if (c == 65)
        move_player_up(global);
    if (c == 66)
        move_player_down(global);
    return 0;
}