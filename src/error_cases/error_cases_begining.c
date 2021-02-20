/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-lenny.garnier
** File description:
** error_cases
*/

#include "my.h"

int error_cases_begining(int ac, char **av)
{
    if (ac != 1 && ac != 2)
        return 84;
    if (ac == 2) {
        if (open(av[1], O_RDONLY) == -1) {
            write(2, "Invalid map entered as argument\n", 32);
            return 84;
        }
    }
    return 0;
}