/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** display_map_arg_opt
*/

#include "my.h"

int launch_client(global_t *global)
{
    int socketClient = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addrClient;

    addrClient.sin_addr.s_addr = inet_addr(global->ip);
    addrClient.sin_family = AF_INET;
    addrClient.sin_port = htons(5050);
    connect(socketClient, (const struct sockaddr *)&addrClient,
        sizeof(addrClient));
    init_ncurses();
    global->game_state = game_on;
    load_map(global, global->arg_map);
    game_loop_online(global);
    return 0;
}

int launch_host_server(global_t *global)
{
    int socketServer = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addrServer;

    addrServer.sin_addr.s_addr = inet_addr(global->ip);
    addrServer.sin_family = AF_INET;
    addrServer.sin_port = htons(5050);
    bind(socketServer, (const struct sockaddr *)&addrServer,
        sizeof(addrServer));
    listen(socketServer, global->player_nb - 1);
    for (int i = 0; i < global->player_nb - 1; i++) {
        struct sockaddr_in  addrClient;
        socklen_t csize = sizeof(addrClient);
        accept(socketServer, (struct sockaddr *)&addrClient,
            &csize);
    }
    load_map(global, global->arg_map);
    global->map = remove_P(global->map);
    global->game_state = game_on;
    game_loop_online(global);
    return 0;
}

global_t *get_player_nb(global_t *global)
{
    int c = 0;

    global->player_nb = 2;
    clear();
    while (c != 10) {
        mvprintw(2, global->tx / 2 - 8, "SET TOTAL PLAYER NUMBER");
        mvprintw(global->ty / 2, global->tx / 2, char_to_str
            (global->player_nb + '0'));
        mvprintw(global->ty / 2, global->tx / 2 + 3, "players");
        mvprintw(global->ty / 2 - 2, global->tx / 2, char_to_str('z'));
        mvprintw(global->ty / 2 + 2, global->tx / 2, char_to_str('s'));
        refresh();
        c = getch();
        if (c == 'z' && global->player_nb != 5)
            global->player_nb += 1;
        if (c == 's' && global->player_nb != 2)
            global->player_nb -= 1;
    }
    clear();
    return global;
}

int display_enter_host_ip(global_t *global)
{
    int c = 0;
    int i = 0;
    char *buffer = malloc(sizeof(char) * 16);

    buffer[0] = '\0';
    while (c != 10 && i != 15) {
        clear();
        mvprintw(global->ty / 2, global->tx / 2, "Enter Host IP");
        if (buffer != NULL)
            mvprintw(global->ty / 2 + 3, global->tx / 2, buffer);
        refresh();
        c = getch();
        if (c == '.')
            buffer[i] = '.';
        else
            buffer[i] = c;
        buffer[i + 1] = '\0';
        i++;
    }
    global->ip = my_strcpy(global->ip, buffer);
    free(buffer);
    return 0;
}

int display_map_arg_opt_menu(global_t *global, char c, int y)
{
    clear();
    mvprintw(2, global->tx / 2 - 5, "ARG MAP MODE");
    mvprintw(6, global->tx / 2 - 4, "SOLO");
    mvprintw(8, global->tx / 2 - 4, "HOST");
    mvprintw(10, global->tx / 2 - 4, "JOIN");
    mvprintw(y, global->tx / 2 - 7, "=>");
    refresh();
    if (c == 10) {
        if (y == 6) {
            load_map(global, global->arg_map);
            global->map = remove_P(global->map);
            global->game_state = game_on;
            return 1;
        }
        if (y == 8) {
            display_enter_host_ip(global);
            global = get_player_nb(global);
            clear();
            mvprintw(global->ty / 2, global->tx / 2 - 6, "Waiting...");
            if (global->ip != NULL)
                mvprintw(global->ty / 2 + 2, global->tx / 2 - 6, global->ip);
            refresh();
            launch_host_server(global);
            return 1;
        }
        if (y == 10) {
            display_enter_host_ip(global);
            launch_client(global);
        }
    }
    return 0;
}

int display_map_arg_opt(global_t *global)
{
    int c = 0;
    int y = 6;

    while (1) {
        if (display_map_arg_opt_menu(global, c, y) == 1)
            return 0;
        c = getch();
        if (c == 65 && y != 6)
            y -= 2;
        if (c == 66 && y != 10)
            y += 2;
    }
    return 0;
}