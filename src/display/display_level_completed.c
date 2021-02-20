/*
** EPITECH PROJECT, 2021
** bonus_v2
** File description:
** display_level_completed
*/

#include "my.h"

int display_no_lvl_6(global_t *global)
{
    clear();
    mvprintw(global->ty / 2, global->tx / 2 - 5,
        "No level 6 yet !");
    refresh();
    sleep(1);
    return 0;
}

int display_level_completed(global_t *global)
{
    char c = 0;
    int y = 6;

    while (1) {
        clear();
        if (is_break_lvl_comp(global, c, y) == 1)
            break;
        display_level_comp_menu(global, y);
        c = getch();
        if (c == 65 && y != 6)
            y -= 2;
        if (c == 66 && y != 10)
            y += 2;
    }
    menu_redirect_level_comp(global, y);
    return 0;
}