/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday08-lenny.garnier
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen_const(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return 0;
}

char *my_strdup(char const *src)
{
    char *buffer = malloc(sizeof(char) * my_strlen_const(src));
    int i = 0;

    while (src[i] != '\0') {
        buffer[i] = src[i];
        i++;
    }
    buffer[i] = '\0';
    return buffer;
}