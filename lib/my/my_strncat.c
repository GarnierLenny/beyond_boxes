/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday07-lenny.garnier
** File description:
** my_strncat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int y = 0;

    nb -= 1;
    while (dest[i] != '\0')
        i++;
    while (y <= nb) {
        if (src[y] == '\0')
            return dest;
        dest[i] = src[y];
        y++;
        i++;
    }
    while (y <= nb)
        dest[i] = '\0';
    return dest;
}
