/*
** EPITECH PROJECT, 2020
** B-CPE-100-RUN-1-1-cpoolday04-lenny.garnier
** File description:
** my_sort_int_array
*/

#include "my.h"

int find_swap_pos(int *array, int size)
{
    int i = 0;

    while (i <= size - 2) {
        if (array[i] > array[i + 1])
            return i;
        i = i + 1;
    }
    return -1;
}

void my_sort_int_array(int *array, int size)
{
    int y = find_swap_pos(array, size);

    while (find_swap_pos(array, size) > -1) {
        my_swap(&array[y], &array[y + 1]);
        y = find_swap_pos(array, size);
    }
}