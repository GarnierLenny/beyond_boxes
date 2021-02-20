/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** display_level_select
*/

#include "my.h"

int figure_lvl_y(int y)
{
    if (y == 4)
        return 1;
    if (y == 2)
        return 2;
    if (y == 0)
        return 3;
    if (y == -2)
        return 4;
    if (y == -4)
        return 5;
    return 0;
}

char *replace_load_level(char *str, int lvl)
{
    char *buffer = my_strdup(str);
    int i = 0;

    for (; buffer[i] != '\0'; i++)
        if (buffer[i] == 'x')
            buffer[i] = lvl + '0';
    return buffer;
}

int display_best(global_t *global, int y)
{
    clear();
    mvprintw(2, global->tx / 2 - 7, "Level Selection");
    mvprintw(6, global->tx / 2 - 4, "1 2 3 4 5");
    mvprintw(7, global->tx / 2 - y, "^");
    mvprintw(global->ty / 2 + 2, global->tx / 2 - 12, "Best moves");
    mvprintw(global->ty / 2 + 3, global->tx / 2 - 8,
        global->highscore->moves[global->highscore->point]);
    mvprintw(global->ty / 2 + 2, global->tx / 2 + 4, "Best time");
    mvprintw(global->ty / 2 + 3, global->tx / 2 + 7,
        global->highscore->time[global->highscore->point]);
    refresh();
    return 0;
}

int display_level_select(global_t *global)
{
    char *buffer = NULL;
    char c = 0;
    int y = 4;

    global->highscore->point = 0;
    while (c != 10) {
        display_best(global, y);
        c = getch();
        if (c == 67 && y != -4) {
            y -= 2;
            global->highscore->point += 1;
        }
        if (c == 68 && y != 4) {
            y += 2;
            global->highscore->point -= 1;
        }
    }
    buffer = replace_load_level("levels/level_x", figure_lvl_y(y));
    load_map(global, buffer);
    global->current = my_strcpy(global->current, buffer);
    global->game_state = game_on;
    free(buffer);
    return 0;
}