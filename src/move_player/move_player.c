/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** move_player
*/

#include "my.h"

global_t *move_player(global_t *global, char *map, int c)
{
    map = map;
    if (c == 32) {
        sfClock_restart(global->clock_h);
        global->moves = 0;
        clear();
        refresh();
        if (global->in_map_arg == 0)
            global = load_map(global, global->current);
        else
            global = load_map(global, global->arg_map);
        global->map = remove_P(global->map);
    } else {
        move_player_y(global, c);
        move_player_x(global, c);
    }
    refresh();
    return global;
}