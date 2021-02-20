/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday03-lenny.garnier
** File description:
** my_isneg
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n >= 0)
        my_putchar('P');
    else
        my_putchar('N');
    return 0;
}