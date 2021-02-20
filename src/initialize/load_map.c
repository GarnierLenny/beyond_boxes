/*
** EPITECH PROJECT, 2021
** bonus_v2
** File description:
** load_map
*/

#include "my.h"

int get_v_hole(global_t *global)
{
    int i = 0;
    int y = 0;

    for (; global->holes[y] != NULL; y++) {
        for (i = 0; global->holes[y][i] != '\0'; i++) {
            if (global->holes[y][i] == 'V')
                global->map[y][i] = 'X';
        }
    }
    return 0;
}

global_t *load_map(global_t *global, char *map)
{
    struct stat sb;
    char *buffer = NULL;
    int fd = open(map, O_RDONLY);

    stat(map, &sb);
    buffer = malloc(sizeof(char) * sb.st_size);
    read(fd, buffer, sb.st_size);
    global->map = str_to_word_array_sep(buffer, '\n');
    global->player->x = find_p(global->map, 0);
    global->player->y = find_p(global->map, 1);
    global->holes = keep_holes(global);
    get_v_hole(global);
    global->holes_nb = find_holes_nb(cpy_ss(global->holes));
    global->map_x = find_map_col_nb(cpy_ss(global->map));
    global->map_y = find_map_line_nb(cpy_ss(global->map));
    return global;
}