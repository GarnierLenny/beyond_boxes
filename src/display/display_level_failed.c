/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** display_level_failed
*/

#include "my.h"

int redirect_menu_level_failed(global_t *global, int y)
{
    if (y == 6) {
        if (global->in_map_arg == 0)
            load_map(global, global->current);
        else
            load_map(global, global->arg_map);
        global->game_state = game_on;
    }
    if (y == 8)
        global->game_state = menu;
    return 0;
}

void display_menu_level_failed(global_t *global, int y)
{
    clear();
    mvprintw(2, global->tx / 2 - 8, "LEVEL FAILED");
    mvprintw(6, global->tx / 2 - 4, "RETRY");
    mvprintw(8, global->tx / 2 - 4, "MAIN MENU");
    mvprintw(y, global->tx / 2 - 7, "=>");
    refresh();
}

int display_level_failed(global_t *global)
{
    char c = 0;
    int y = 6;

    while (c != 10) {
        display_menu_level_failed(global, y);
        c = getch();
        if (c == 65 && y != 6)
            y -= 2;
        if (c == 66 && y != 8)
            y += 2;
    }
    redirect_menu_level_failed(global, y);
    return 0;
}