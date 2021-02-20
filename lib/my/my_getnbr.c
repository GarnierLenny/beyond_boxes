/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday04-lenny.garnier
** File description:
** test
*/

#include <stdio.h>

void my_putchar(char c);

int is_num1(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    if (c == '-' || c == '+')
        return 2;
    return 0;
}

int find_div1(char const *str)
{
    int div = 1;
    int i = 0;

    while (str[i + 1] != '\0') {
        if (is_num1(str[i]) == 1) {
            if (is_num1(str[i + 1]) != 1)
                return div;
            div *= 10;
        }
        i++;
    }
    return div;
}

char get_sign(char const *str)
{
    char sign;
    int i = 0;

    if (is_num1(str[i]) == 2)
        sign = str[i];
    while (is_num1(str[i]) != 1) {
        if (is_num1(str[i + 1]) == 2 && sign != str[i + 1])
            sign = '-';
        else if (is_num1(str[i + 1]) == 2 && sign == str[i + 1])
            sign = '+';
        i++;
    }
    return sign;
}

int my_getnbr(char const *str)
{
    int div = find_div1(str);
    int i = 0;
    int res = 0;

    if (is_num1(str[0]) == 0)
        return 0;
    if (find_div1(str) == 0)
        return 0;
    while (is_num1(str[i]) != 1)
        i++;
    if (is_num1(str[0]) == 2)
        get_sign(str);
    while (div >= 1) {
        res += (str[i] - '0') * div;
        div /= 10;
        i++;
    }
    if (get_sign(str) == '-')
        res *= -1;
    return res;
}
