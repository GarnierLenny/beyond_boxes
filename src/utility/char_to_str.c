/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-lenny.garnier
** File description:
** char_to_str
*/

#include "my.h"

char *char_to_str(char c)
{
    char *buffer = malloc(sizeof(char) * 2);

    buffer[0] = c;
    buffer[1] = '\0';
    return buffer;
}