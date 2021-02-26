/*
** EPITECH PROJECT, 2021
** my_sokoban
** File description:
** display_map_editor
*/

#include "my.h"

char **reset_map(char **tab)
{
    int line = 1;

    for (; tab[line + 1] != NULL; line++) {
        tab[line] = my_strcpy(tab[line],
            "#                  #\n");
    }
    return tab;
}

char **put_char_tab(char **tab, int c, global_t *global)
{
    if (c == 97)
        tab[global->ymap][global->xmap] = 'P';
    if (c == 122)
        tab[global->ymap][global->xmap] = 'X';
    if (c == 101)
        tab[global->ymap][global->xmap] = 'O';
    if (c == 114)
        tab[global->ymap][global->xmap] = '#';
    if (c == 116)
        tab[global->ymap][global->xmap] = ' ';
    if (c == 110)
        tab = reset_map(tab);
    return tab;
}

int create_map_file(char **map)
{
    int fd = open("custom_map", O_CREAT | O_RDWR, 0777);
    int i = 0;

    for (; map[i] != NULL; i++)
        write(fd, map[i], my_strlen(map[i]));
    close(fd);
    return 0;
}

int display_map_finished(global_t *global)
{
    clear();
    mvprintw(global->ty / 2, global->tx / 2, "Finishing map...");
    refresh();
    sleep(1);
    clear();
    mvprintw(global->ty / 2, global->tx / 2 - 5, "Map finished !");
    mvprintw(global->ty / 2 + 2, global->tx / 2 - 20,
        "Relaunch the game with 'custom_map' as argument");
    mvprintw(global->ty / 2 + 4, global->tx / 2 - 10,
        "Press any key to exit...");
    getch();
    exit_status(0, 0);
    return 0;
}

int display_map_editor(global_t *global)
{
    char **tab = retrieve_file_content("map_editor_sample");
    int c = 0;
    int yc = 2;
    int xc = 10;

    global->xmap = 1;
    global->ymap = 1;
    curs_set(TRUE);
    for (; c != 10; ) {
        display_map_editor_misc(global, tab, yc, xc);
        c = getch();
        tab = put_char_tab(tab, c, global);
        update_xm(&xc, global, c);
        update_ym(&yc, global, c);
    }
    create_map_file(tab);
    display_map_finished(global);
    return 0;
}