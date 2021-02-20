/*
** EPITECH PROJECT, 2021
** bonus_v2
** File description:
** display_level_completed_misc
*/

#include "my.h"

int is_break_lvl_comp(global_t *global, char c, int y)
{
    if (c == 10 && y == 6 && global->in_map_arg == 1) {
        clear();
        mvprintw(global->ty / 2, global->tx / 2 - 20,
            "No next level available for argument map mode !");
        refresh();
        sleep(1);
        clear();
        return 0;
    } else if (c == 10)
        return 1;
    return 0;
}

int display_level_comp_menu(global_t *global, int y)
{
    mvprintw(2, global->tx / 2 - 5, "LEVEL COMPLETED !");
    mvprintw(6, global->tx / 2 - 4, "NEXT LEVEL");
    mvprintw(8, global->tx / 2 - 4, "RETRY");
    mvprintw(10, global->tx / 2 - 4, "MAIN MENU");
    mvprintw(y, global->tx / 2 - 7, "=>");
    refresh();
    return 0;
}

char *inc_level(char *buffer)
{
    int i = 0;
    char *str = NULL;

    str = my_strdup(buffer);
    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            str[i] += 1;
    }
    return str;
}

int is_level_upable(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        if (str[i] == '5')
            return 0;
    return 1;
}

int menu_redirect_level_comp(global_t *global, int y)
{
    if (y == 8) {
        if (global->in_map_arg == 1)
            load_map(global, global->arg_map);
        else
            load_map(global, global->current);
        global->map = remove_P(global->map);
        global->game_state = game_on;
    }
    if (y == 10)
        global->game_state = menu;
    if (y == 6 && global->in_map_arg == 0) {
        if (is_level_upable(global->current) == 1) {
            global->current = inc_level(global->current);
            global->highscore->point += 1;
            load_map(global, global->current);
            global->game_state = game_on;
        } else
            display_no_lvl_6(global);
    }
    return 0;
}