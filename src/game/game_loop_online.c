/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** game_loop_online
*/

#include "my.h"

int display_space_pause(global_t *global)
{
    int c = 0;

    while (c != ' ') {
        clear();
        mvprintw(global->ty / 2, global->tx / 2 - 10, "Press space to launch");
        refresh();
        c = getch();
    }
    global->clock_h = sfClock_create();
    clear();
    return 0;
}

global_t *reset_map_on(global_t *global)
{
    sfClock_restart(global->clock_h);
    global->moves = 0;
    clear();
    if (global->in_map_arg == 0)
        global = load_map(global, global->current);
    else
        global = load_map(global, global->arg_map);
    global->map = remove_P(global->map);
    refresh();
    return global;
}

int init_game_loop_on(global_t *global)
{
    global->map = remove_P(global->map);
    display_space_pause(global);
    global->moves = 0;
    global->seconds = 0;
    return 0;
}

int game_loop_online(global_t *global)
{
    struct winsize w;
    int x = 0;
    int y = 0;

    init_game_loop_on(global);
    for (; 1; x = x, y = y) {
        clear();
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        getmaxyx(stdscr, y, x);
        if (w.ws_col < global->map_x + 3 || w.ws_row < global->map_y) {
            print_size_msg(w.ws_col, w.ws_row);
        } else {
            if (disp_all(global) == 1)
                global = reset_map_on(global);
            else
                global = move_player(global, global->current, getch());
        }
    }
    endwin();
    return 0;
}