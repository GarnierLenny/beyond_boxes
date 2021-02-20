/*
** EPITECH PROJECT, 2020
** B-MAT-100-RUN-1-1-101pong-lenny.garnier
** File description:
** usage
*/

#include "my.h"

int str_comp(char *s1, char *s2)
{
    for (int i = 0; s1[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return 0;
    return 1;
}

int usage(int ac, char **av)
{
    if (ac == 2 && str_comp(av[1], "-h") == 1) {
        my_putstr("USAGE\n");
        my_putstr("     ./my_sokoban {map}\n");
        my_putstr("     map: load custom map");
        my_putstr("DESCRIPTION\n");
        my_putstr("     map file representing the warehouse map, containing");
        my_putstr(" '#' for walls, 'P' for player, 'X' for boxes and");
        my_putstr(" 'O' for storage locations.\n");
        my_putstr(" The 5 levels of this my_sokoban ");
        my_putstr("are from the Nokia version.\n");
        return 1;
    }
    return 0;
}