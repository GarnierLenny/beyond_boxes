/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** init_global
*/

#include "my.h"

int check_validity(char *map)
{
    int fd = open(map, O_RDONLY);
    char *buffer = NULL;
    struct stat sb;
    char **arr = NULL;

    stat(map, &sb);
    buffer = malloc(sizeof(char) * sb.st_size);
    read(fd, buffer, sb.st_size);
    arr = str_to_word_array_sep(buffer, '\n');
    if (error_cases_map(arr) == 84)
        return 84;
    return 0;
}

char **get_best(char *path)
{
    struct stat sb;
    char *buffer = NULL;
    char **tab = NULL;
    int fd = open(path, O_RDONLY);

    stat(path, &sb);
    buffer = malloc(sizeof(char) * sb.st_size);
    read(fd, buffer, sb.st_size);
    tab = str_to_word_array_sep(buffer, '\n');
    free(buffer);
    return tab;
}

global_t *init_global(global_t *global, char *map)
{
    struct winsize w;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    global->player = malloc(sizeof(player_t));
    global->highscore = malloc(sizeof(highscore_t));
    global->tx = w.ws_col;
    global->ty = w.ws_row;
    global->current = my_strcpy(global->current, "levels/level_1");
    global->highscore->moves = get_best("src/best/best_moves");
    global->highscore->time = get_best ("src/best/best_time");
    if (map != NULL) {
        if (check_validity(map) == 0) {
            global->arg_map = my_strcpy(global->arg_map, map);
            global->is_map_arg = 1;
        } else {
            global->arg_map = NULL;
            global->is_map_arg = 0;
        }
    } else {
        global->is_map_arg = 0;
    }
    return global;
}