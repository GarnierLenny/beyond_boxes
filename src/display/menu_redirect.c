/*
** EPITECH PROJECT, 2021
** bonus_v2
** File description:
** menu_redirect
*/

#include "my.h"

int menu_redirect(global_t *global, int y)
{
    if (y == 6) {
        global->in_map_arg = 0;
        global->game_state = level_select;
        /* load_map(global, global->current);
        global->map = remove_P(global->map);
        global->game_state = game_on; */
    }
    else if (y == 8) {
        load_map(global, global->arg_map);
        global->map = remove_P(global->map);
        global->in_map_arg = 1;
        global->game_state = game_on;
    }
    else if (y == 10) {
        display_exit_screen(global);
    }
    return 0;
}