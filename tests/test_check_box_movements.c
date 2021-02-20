/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-lenny.garnier
** File description:
** test_check_box_movements
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(check_boxes_movements, test_check_box_1)
{
    char *av[] = {  "##########",
                    "#    P   #",
                    "#       ##",
                    "# X      #",
                    "##########", 0 };

    cr_assert_eq(check_boxes_movements(av), 0);
}

Test(check_boxes_movements, test_check_box_2)
{
    char *av[] = {  "##########",
                    "#    P   #",
                    "#       ##",
                    "#X       #",
                    "##########", 0 };

    cr_assert_eq(check_boxes_movements(av), 1);
}