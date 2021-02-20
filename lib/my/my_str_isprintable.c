/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday06-lenny.garnier
** File description:
** my_str_isprintable
*/

#include <stdio.h>

int char_is_printable(char c)
{
    if (c >= 33 && c <= 126)
        return 1;
    return 0;
}

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (char_is_printable(str[i]) == 0)
            return 0;
        i++;
    }
    return 1;
}
