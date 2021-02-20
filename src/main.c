/*
** EPITECH PROJECT, 2020
** ncurses_test
** File description:
** test
*/

#include "my.h"

int main(int ac, char **av)
{
    global_t *global = malloc(sizeof(global_t));

    if (usage(ac, av) == 1)
        return 0;
    if (error_cases_begining(ac, av) == 84)
        return 84;
    if (av[1] != NULL) {
        init_global(global, av[1]);
    } else
        init_global(global, NULL);
    init_ncurses();
    global->game_state = menu;
    display_game_state(global);
    free(global);
    return 0;
}