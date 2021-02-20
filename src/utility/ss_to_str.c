/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** ss_to_str
*/

#include "my.h"

int find_ss_size(char **tab)
{
    int line = 0;
    int size = 0;

    for (; tab[line] != NULL; line++) {
        size += my_strlen(tab[line]);
    }
    return size;
}

char *ss_to_str(char **tab)
{
    int i = 0;
    int line = 0;
    int x = 0;
    char *buffer = malloc(sizeof(char) * find_ss_size(tab));

    for (; tab[line] != NULL; line++) {
        for (i = 0; tab[line][i] != '\0'; i++, x++)
            buffer[x] = tab[line][i];
    }
    buffer[x] = '\0';
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n' && buffer[i + 1] == '\n') {
            buffer[i + 1] = '\0';
            break;
        }
    }
    return buffer;
}