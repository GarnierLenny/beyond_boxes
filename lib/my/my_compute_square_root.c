/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday05-lenny.garnier
** File description:
** my_compute_square_root
*/

#include <stdio.h>

int my_compute_square_root(int nb)
{
    int a = 1;

    while ((a * a) < nb)
        a++;
    if ((a * a) == nb)
        return a;
    return 0;
}