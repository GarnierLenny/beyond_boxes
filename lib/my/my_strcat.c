/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday07-lenny.garnier
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int y = 0;

    while (dest[i] != '\0')
        i++;
    while (src[y] != '\0') {
        dest[i] = src[y];
        y++;
        i++;
    }
    dest[i] = '\0';
    return dest;
}