/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday05-lenny.garnier
** File description:
** my_is_prime
*/

int my_is_prime(int nb)
{
    int a = 2;

    if (nb == 2)
        return 1;
    if (nb <= 1)
        return 0;
    while (a != nb - 1) {
        if ((nb % a) == 0)
            return 0;
        a++;
    }
    return 1;
}