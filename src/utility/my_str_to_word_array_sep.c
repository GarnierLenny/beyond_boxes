/*
** EPITECH PROJECT, 2020
** rush_test
** File description:
** str_to_word_array
*/

#include <stdio.h>
#include <stdlib.h>

int find_word_nb_sep(char *str, char separator)
{
    int words = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == separator)
            words++;
    return words;
}

int find_word_size_nb_sep(char *str, char separator, int nb)
{
    int size = 0;
    int ref = 0;

    for (int i = 0; str[i] != '\0'; i++, size++) {
        if (str[i] == separator) {
            if (ref == nb)
                return size;
            else {
                ref++;
                size = -1;
            }
        }
    }
    return size;
}

char **malloc_ss_sep(char *str, char separator)
{
    char **buffer = malloc(sizeof(char *)
        * find_word_nb_sep(str, separator));

    for (int i = 0; i <= find_word_nb_sep(str, separator); i++)
        buffer[i] = malloc(sizeof(char)
        * find_word_size_nb_sep(str, separator, i));
    return buffer;
}

char **str_to_word_array_sep(char *str, char separator)
{
    char **buffer = malloc_ss_sep(str, separator);
    int ii = 0;
    int line = 0;

    for (int iy = 0; str[iy] != '\0'; iy++, ii++) {
        buffer[line][ii] = str[iy];
        if (str[iy] == separator) {
            line++;
            ii = -1;
        }
    }
    buffer[line] = NULL;
    return buffer;
}