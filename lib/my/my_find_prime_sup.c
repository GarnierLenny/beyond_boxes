/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday05-lenny.garnier
** File description:
** my_find_prime_sup
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int a = nb;

    if (my_is_prime(nb) == 1)
        return nb;
    while (my_is_prime(a) == 0) {
        a++;
    }
    return a;
}