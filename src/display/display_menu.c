/*
** EPITECH PROJECT, 2021
** bonus_v2
** File description:
** display_menu
*/

#include "my.h"

int is_break(global_t *global, char c, int y)
{
    if (c == 10) {
        if (y == 6 || y == 10 || y == 12)
            return 1;
        if (y == 8 && global->is_map_arg == 1)
            return 1;
        else {
            clear();
            mvprintw(global->ty / 2, global->tx / 2 - 10,
                "No valid map entered as argument !");
            refresh();
            sleep(1);
        }
    }
    return 0;
}

void display_menu_options(int x, int y)
{
    clear();
    mvprintw(2, x / 2 - 4, "MY_SOKOBAN");
    mvprintw(6, x / 2 - 2, "PLAY");
    mvprintw(8, x / 2 - 2, "PLAY ARGUMENT MAP");
    mvprintw(10, x / 2 - 2, "CUSTOM MAP EDITOR");
    mvprintw(12, x / 2 - 2, "EXIT");
    mvprintw(y, x / 2 - 5, "=>");
}

int display_menu(global_t *global)
{
    char c = 0;
    int y = 6;

    while (1) {
        if (is_break(global, c, y) == 1)
            break;
        display_menu_options(global->tx, y);
        refresh();
        c = getch();
        if (c == 65 && y != 6) {
            clear();
            y -= 2;
        }
        if (c == 66 && y != 12)
            y += 2;
        refresh();
    }
    menu_redirect(global, y);
    return 0;
}