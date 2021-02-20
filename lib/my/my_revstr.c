/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday06-lenny.garnier
** File description:
** my_revstr
*/

#include <stdio.h>
#include <string.h>

int my_strlen(char *str);

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char c;

    while (j >= i) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }
    return str;
}