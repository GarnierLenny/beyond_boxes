/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday04-lenny.garnier
** File description:
** my_swap
*/

void my_putchar(char c);

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}