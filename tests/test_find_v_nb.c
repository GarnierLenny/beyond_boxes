/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-lenny.garnier
** File description:
** test_find_v_nb
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(find_v_nb, test_find_v_nb)
{
    char *av[] = {  "##########",
                    "#    V   #",
                    "#       ##",
                    "#V     V #",
                    "##########", 0 };

    cr_assert_eq(find_v_nb(av), 3);
}