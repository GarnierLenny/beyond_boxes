/*
** EPITECH PROJECT, 2021
** bonus_v2
** File description:
** display_exit_screen
*/

#include "my.h"

int display_exit_screen(global_t *global)
{
    clear();
    mvprintw(global->ty / 2, global->tx / 2 - 5, "Thanks for playing !");
    free(global);
    exit_status(0, 1);
    return 0;
}