/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-lenny.garnier
** File description:
** exit_status
*/

#include "my.h"

void exit_status(int exit_num, int x)
{
    refresh();
    sleep(x);
    clear();
    endwin();
    exit(exit_num);
}