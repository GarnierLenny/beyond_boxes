/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday07-lenny.garnier
** File description:
** my_sort_params
*/

#include "my.h"

void disp_char_ss(char **buffer)
{
    int i = 0;

    while (buffer[i] != NULL) {
        my_putstr(buffer[i]);
        my_putchar('\n');
        i++;
    }
}

int is_av_ascend(char **av)
{
    int i = 0;

    while (av[i + 1] != NULL) {
        if (my_strcmp(av[i], av[i + 1]) > 0)
            return 0;
        i++;
    }
    return 1;
}

char **swap_pos(char **av, int *i, int *y)
{
    char *str;

    str = av[*i];
    av[*i] = av[*y];
    av[*y] = str;
    *i += 1;
    *y += 1;
    return av;
}

int test(int argc, char **argv)
{
    int i = 0;
    int y = 1;
    char *str;

    while (is_av_ascend(argv) == 0) {
        if (argv[y] == 0) {
            i = 0;
            y = 1;
        }
        while (argv[y] != 0) {
            if (my_strcmp((const)argv[i], (const)argv[y]) < 0) {
                y++;
                i++;
            } else
                argv = swap_pos(argv, &i, &y);
        }
    }
    disp_char_ss(argv);
    return 0;
}