/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday06-lenny.garnier
** File description:
** my_str_is_num
*/

#include <stdio.h>

int char_is_num(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (char_is_num(str[i]) != 1)
            return 0;
        i++;
    }
    return 1;
}
