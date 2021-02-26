/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** display_map_editor_mics
*/

#include "my.h"

char **retrieve_file_content(char *map)
{
    struct stat sb;
    char **tab = NULL;
    int fd = open(map, O_RDONLY);
    char *buffer = NULL;

    stat(map, &sb);
    buffer = malloc(sizeof(char) * sb.st_size);
    read(fd, buffer, sb.st_size);
    tab = str_to_word_array_sep(buffer, '\n');
    free(buffer);
    return tab;
}

void display_map_editor_misc(global_t *global, char **tab, int yc, int xc)
{
    clear();
    mvprintw(2, global->tx / 2 - 10, "CUSTOM MAP EDITOR");
    for (int i = 0; tab[i] != NULL; i++)
        mvprintw((global->ty / 2) - 3 + i, global->tx / 2 - 11, tab[i]);
    mvprintw(global->ty / 2 - 3, global->tx / 2 + 20, "'a': place a 'P'");
    mvprintw(global->ty / 2 - 1, global->tx / 2 + 20, "'z': place a 'X'");
    mvprintw(global->ty / 2 + 1, global->tx / 2 + 20, "'e': place a 'O'");
    mvprintw(global->ty / 2 + 3, global->tx / 2 + 20, "'r': place a '#'");
    mvprintw(global->ty / 2 + 5, global->tx / 2 + 20,
        "'t': empty current slot");
    mvprintw(global->ty / 2 + 7, global->tx / 2 + 20, "'n': reset map");
    move((global->ty / 2) - yc, global->tx / 2 - xc);
    refresh();
}

int update_xm(int *xc, global_t *global, int c)
{
    if (c == 67 && *xc > -7) {
        *xc -= 1;
        global->xmap++;
    }
    if (c == 68 && *xc < 10) {
        *xc += 1;
        global->xmap--;
    }
    return 0;
}

int update_ym(int *yc, global_t *global, int c)
{
    if (c == 65 && *yc < 2) {
        *yc += 1;
        global->ymap--;
    }
    if (c == 66 && *yc > -6) {
        *yc -= 1;
        global->ymap++;
    }
    return 0;
}