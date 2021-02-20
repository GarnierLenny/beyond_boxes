/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday03-lenny.garnier
** File description:
** tests_my_isneg
*/

#include <stdio.h>

void my_putchar(char c);

int find_dig(int nb)
{
    int div = 1;

    while ((div * 10) < nb) {
        div *= 10;
    }
    if (nb == 10)
        div *= 10;
    if (nb == 100)
        div *= 10;
    return div;
}

int my_put_nbr(int nb)
{
    int div;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb == 0) {
        my_putchar('0');
        return 0;
    }
    div = find_dig(nb);
    while (div > 0) {
        my_putchar((nb / div) + 48);
        nb = nb % div;
        div /= 10;
    }
    return 0;
}