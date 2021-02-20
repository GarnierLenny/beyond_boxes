/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday03-lenny.garnier
** File description:
** tests_my_isneg
*/

#include "my.h"

void my_putchar(char c);

int find_dig_nb(int nb)
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

char *int_to_str(int nb)
{
    int div = 0;
    char *buffer = malloc(sizeof(char) * find_dig_nb(nb));
    int i = 0;

    if (nb == 0) {
        buffer[i] = '0';
        buffer[i + 1] = '\0';
        return buffer;
    }
    div = find_dig_nb(nb);
    while (div > 0) {
        buffer[i] = (nb / div) + 48;
        i++;
        nb = nb % div;
        div /= 10;
    }
    buffer[i] = '\n';
    return buffer;
}