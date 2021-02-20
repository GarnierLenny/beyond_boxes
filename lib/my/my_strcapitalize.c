/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday06-lenny.garnier
** File description:
** my_strcapitalize
*/

#include <stdio.h>

int is_alpha(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 2;
    return 0;
}

int is_minus_plus(char c)
{
    if (c == '-' || c == '+')
        return 1;
    return 0;
}

int is_word_beg(char c, int i)
{
    if (c == ' ' || (is_minus_plus(c) == 1 || i == 0))
        return 1;
    return 0;
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_alpha(str[i]) == 1 &&
            is_word_beg(str[i - 1], i) == 1)
            str[i] -= 32;
        else if (is_alpha(str[i]) == 2 &&
                is_word_beg(str[i - 1], i) == 0)
            str[i] += 32;
        i++;
    }
    return str;
}