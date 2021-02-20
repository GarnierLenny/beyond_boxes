/*
** EPITECH PROJECT, 2021
** sokoban
** File description:
** disp_all
*/

#include "my.h"

int print_size_msg(int x, int y)
{
    mvprintw((y / 2), (x / 2) - 14, "The terminal must be resized");
    refresh();
    clear();
    return 0;
}

int get_dig_nb(int nb)
{
    int i = 1;
    int digits = 0;

    for (; i < nb; i *= 10, digits++);
    return digits;
}

global_t *display_timer(global_t *global)
{
    float timer_f = 0;
    char *buffer = malloc(sizeof(char) * 5);

    timer_f = sfTime_asSeconds
        (sfClock_getElapsedTime(global->clock_h));
    buffer = gcvt(timer_f, get_dig_nb((int)timer_f) + 3, buffer);
    mvprintw(global->map_y / 2 - 1, global->map_x + 4, "Timer");
    mvprintw(global->map_y / 2, global->map_x + 4, buffer);
    mvprintw(global->map_y / 2, global->map_x + 11, "seconds");
    global->seconds = atof(buffer);
    free(buffer);
    return global;
}

int display_moves(global_t *global)
{
    float nb = global->moves;
    char *buffer = malloc(sizeof(char) * 4);

    mvprintw(global->map_y / 2 + 2, global->map_x + 4, "Moves");
    mvprintw(global->map_y / 2 + 3, global->map_x + 4, gcvt(nb, 3, buffer));
    refresh();
    getch();
    free(buffer);
    return 0;
}

char *add_br(char *buffer)
{
    char *str = malloc(sizeof(char) * (my_strlen(buffer) + 1));
    int i = 0;

    for (; buffer[i] != '\0'; i++)
        str[i] = buffer[i];
    str[i] = '\n';
    str[i + 1] = '\0';
    return str;
}

global_t *check_scores(global_t *global)
{
    int point = global->highscore->point;
    char *buffer = malloc(sizeof(char) * 5);
    int fd = open("src/best/best_moves", O_RDWR);
    char *str = NULL;

    if (global->moves <
        my_getnbr(global->highscore->moves[point])) {
            global->highscore->moves[point] = my_strcpy(
            global->highscore->moves[point], int_to_str(global->moves));
        }
    str = ss_to_str(global->highscore->moves);
    write(fd, str, my_strlen(str));
    fd = open("src/best/best_time", O_RDWR);
    if (global->seconds < atof(global->highscore->time[point])) {
        global->highscore->time[point] =
            my_strcpy(global->highscore->time[point],
            gcvt(global->seconds, 4, buffer));
        global->highscore->time[point] =
            add_br(global->highscore->time[point]);
    }
    str = ss_to_str(global->highscore->time);
    write(fd, str, my_strlen(str));
    free(buffer);
    return global;
}

int disp_all(global_t *global)
{
    disp_map_n(global->map);
    global->holes = disp_holes(cpy_ss(global->map), cpy_ss(global->holes));
    mvprintw(global->player->y, global->player->x, "P");
    if (find_v_nb(cpy_ss(global->holes)) == global->holes_nb) {
        global->game_state = level_completed;
        display_timer(global);
        display_moves(global);
        global = check_scores(global);
        return 1;
    }
    else if (check_boxes_movements(cpy_ss(global->map)) == 1) {
        global->game_state = level_failed;
        return 1;
    }
    return 0;
}