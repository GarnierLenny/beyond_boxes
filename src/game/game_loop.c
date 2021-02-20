/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** game_loop
*/

#include "my.h"

global_t *game_loop(global_t *global)
{
    struct winsize w;
    int x = 0;
    int y = 0;

    global->map = remove_P(global->map);
    global->clock_h = sfClock_create();
    global->moves = 0;
    global->seconds = 0;
    for (; 1; x = x, y = y) {
        clear();
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        getmaxyx(stdscr, y, x);
        if (w.ws_col < global->map_x + 3 || w.ws_row < global->map_y) {
            print_size_msg(w.ws_col, w.ws_row);
        } else {
            if (disp_all(global) == 1)
                return global;
            global = move_player(global, global->current, getch());
        }
    }
    endwin();
    return global;
}