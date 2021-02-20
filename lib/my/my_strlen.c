/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday04-lenny.garnier
** File description:
** my_strlen
*/

void my_putchar(char c);

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}