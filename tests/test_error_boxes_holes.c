/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-lenny.garnier
** File description:
** test_error_boxes_holes
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(error_boxes_holes, test_ec_3)
{
    char *av[] = {  "##########",
                    "#        #",
                    "##########", 0 };

    cr_assert_eq(error_boxes_holes(av), 84);
}