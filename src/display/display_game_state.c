/*
** EPITECH PROJECT, 2021
** bonus_v2
** File description:
** display_game_state
*/

#include "my.h"

int display_game_state(global_t *global)
{
    while (1) {
        clear();
        if (global->game_state == menu)
            display_menu(global);
        else if (global->game_state == game_on) {
            game_loop(global);
        }
        else if (global->game_state == level_completed) {
            display_level_completed(global);
        }
        else if (global->game_state == level_failed)
            display_level_failed(global);
        else if (global->game_state == level_select)
            display_level_select(global);
        else if (global->game_state == map_editor)
            display_map_editor(global);
        else if (global->game_state == arg_map_opt)
            display_map_arg_opt(global);
    }
    return 0;
}