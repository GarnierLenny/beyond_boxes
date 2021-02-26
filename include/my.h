/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday07-lenny.garnier
** File description:
** my
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ncurses.h>
#include <curses.h>
#include <time.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define scp my_strcpy
#define gnb my_getnbr
#define its int_to_str
#define bf buffer

#ifndef MY_H_
#define MY_H_

typedef struct highcore_s {
    int point;
    char **moves;
    char **time;
} highscore_t;

typedef enum game_state_s {
    menu,
    level_select,
    map_editor,
    set_player_nb,
    arg_map_opt,
    game_on,
    level_failed,
    level_completed,
    exit_screen,
} game_state_t;

typedef struct player_s {
    int x;
    int y;
    int v;
} player_t;

typedef struct global_s {
    char **map;
    char **holes;
    player_t *player;
    int holes_nb;
    int map_x;
    int map_y;
    int tx;
    int ty;
    char *current;
    char *arg_map;
    int is_map_arg;
    int in_map_arg;
    float seconds;
    sfClock *clock_h;
    int moves;
    int xmap;
    int ymap;
    int player_nb;
    char *ip;
    game_state_t game_state;
    highscore_t *highscore;
} global_t;

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char *src);
int find_line_nb(char **tab);
int usage(int ac, char **av);
void init_ncurses(void);
char **str_to_word_array_sep(char *str, char separator);
global_t *init_global(global_t *global, char *map);
void disp_map_n(char **map);
int disp_all(global_t *global);
global_t *move_player(global_t *global, char *map, int c);
global_t *game_loop(global_t *global);
int move_player_x(global_t *global, int c);
int move_player_y(global_t *global, int c);
char **cpy_ss(char **buffer);
char **disp_holes(char **map, char **holes);
char *char_to_str(char c);
void exit_status(int exit_num, int x);
int check_boxes_movements(char **map);
int check_one_box_mov(char **map, int y, int x);
int is_char_block(char c);
int find_v_nb(char **holes);
int error_cases_begining(int ac, char **av);
int error_cases_map(char **map);
int error_map_invalid_char(char **map);
char **remove_P(char **map);
int error_map_pnb(char **map);
int error_boxes_holes(char **map);
int print_size_msg(int x, int y);
int is_char_correct(char c);
int display_menu(global_t *global);
char *my_strdup(char const *src);
int display_exit_screen(global_t *global);
int menu_redirect(global_t *global, int y);
int display_game_state(global_t *global);
int str_comp(char *s1, char *s2);
global_t *load_map(global_t *global, char *map);
char **remove_P(char **map);
int find_p(char **map, int option);
char **keep_holes(global_t *global);
int find_holes_nb(char **map);
int find_map_line_nb(char **map);
int find_map_col_nb(char **map);
int display_level_completed(global_t *global);
int menu_redirect_level_comp(global_t *global, int y);
int is_level_upable(char *str);
char *inc_level(char *buffer);
int display_level_comp_menu(global_t *global, int y);
int is_break_lvl_comp(global_t *global, char c, int y);
int display_no_lvl_6(global_t *global);
int display_level_failed(global_t *global);
void display_menu_level_failed(global_t *global, int y);
int redirect_menu_level_failed(global_t *global, int y);
int display_level_select(global_t *global);
global_t *display_timer(global_t *global);
char *ss_to_str(char **tab);
char *int_to_str(int nb);
int display_map_editor(global_t *global);
void display_map_editor_misc(global_t *global, char **tab, int yc, int xc);
char **retrieve_file_content(char *map);
int update_ym(int *yc, global_t *global, int c);
int update_xm(int *yc, global_t *global, int c);
void display_map_editor_misc(global_t *global, char **tab, int yc, int xc);
char **retrieve_file_content(char *map);
int display_map_arg_opt(global_t *global);
int game_loop_online(global_t *global);
int display_space_pause(global_t *global);
int game_loop_online(global_t *global);
int init_game_loop_on(global_t *global);
global_t *reset_map_on(global_t *global);
int display_space_pause(global_t *global);

#endif /* !MY_H_ */