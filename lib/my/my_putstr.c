/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday04-lenny.garnier
** File description:
** my_putstr
*/

void my_putchar(char c);

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}
