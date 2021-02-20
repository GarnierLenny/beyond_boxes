/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday05-lenny.garnier
** File description:
** my_compute_power_rec
*/

#include <stdio.h>

int my_compute_power_rec(int nb, int p)
{
    int res = nb;

    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    else
        return (res * my_compute_power_rec(nb, p - 1));
    return (res * nb);
}