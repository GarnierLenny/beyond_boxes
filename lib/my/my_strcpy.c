/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday06-lenny.garnier
** File description:
** my_strcpy
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_strcpy(char *dest, char *str)
{
    int i = 0;
    char *tmp = malloc(sizeof(char) * my_strlen(str));

    while (str[i] != '\0') {
        tmp[i] = str[i];
        i++;
    }
    tmp[i] = '\0';
    return tmp;
}