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
    }
    else if (y == 8) {
        global->in_map_arg = 1;
        global->game_state = arg_map_opt;
    }
    if (y == 10)
        global->game_state = map_editor;
    else if (y == 12) {
        display_exit_screen(global);
    }
    return 0;
}