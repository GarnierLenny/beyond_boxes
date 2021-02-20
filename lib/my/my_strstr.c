/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday06-lenny.garnier
** File description:
** my_strstr
*/

int my_strlen(char *str);

char *pop_front(char *str)
{
    char *buffer = str;
    int i = 0;
    int j = 1;

    while (str[j] != '\0') {
        buffer[i] = str[j];
        i++;
        j++;
    }
    buffer[i] = '\0';
    return buffer;
}

int str_comp(char *comp, char const *to)
{
    int i = 0;

    while (to[i] != '\0') {
        if (comp[i] != to[i])
            return 0;
        i++;
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    return 0;
}
