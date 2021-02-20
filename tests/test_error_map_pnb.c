/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-lenny.garnier
** File description:
** test_error_map_pnb
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(error_map_pnb, test_ec_5)
{
    char *av[] = {  "##########",
                    "#  P   P #",
                    "##########", 0 };

    cr_assert_eq(error_map_pnb(av), 84);
}