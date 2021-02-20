/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday06-lenny.garnier
** File description:
** my_str_islower
*/

#include <stdio.h>

int is_char_lower(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_char_lower(str[i]) == 0)
            return 0;
        i++;
    }
    return 1;
}
