/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** cpy_ss
*/

#include "my.h"

int find_line_nb(char **tab)
{
    int line = 0;

    for (; tab[line] != NULL; line++);
    return line;
}

char **cpy_ss(char **buffer)
{
    char **tab = malloc(sizeof(char *) * (find_line_nb(buffer) + 1));
    int line = 0;

    for (; buffer[line] != NULL; line++)
        tab[line] = my_strcpy(tab[line], buffer[line]);
    tab[line] = NULL;
    return tab;
}