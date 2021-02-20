/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday06-lenny.garnier
** File description:
** my_strcmp
*/

#include <stdio.h>
#include <string.h>

int check_sup(char *s1, char *s2, int i)
{
    if (s1[i] > s2[i])
        return 1;
    else
        return -1;
    return 0;
}

int check_sup_const(char const *s1, char const *s2, int i)
{
    if (s1[i] > s2[i])
        return 1;
    else
        return -1;
    return 0;
}

int my_strcmp_const(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        if (check_sup_const(s1, s2, i) == 1) {
            return 1;
        } else
            return -1;
        i++;
    }
    return 0;
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        if (check_sup(s1, s2, i) == 1) {
            return 1;
        } else
            return -1;
        i++;
    }
    return 0;
}