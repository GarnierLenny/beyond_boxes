/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** init_ncurses
*/

#include "my.h"

void init_ncurses(void)
{
    initscr();
    noecho();
    curs_set(FALSE);
}