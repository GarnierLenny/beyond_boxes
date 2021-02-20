/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-lenny.garnier
** File description:
** test_error_map_invalid_char
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(error_map_invalid_char, test_ec_6)
{
    char *av[] = {  "##########",
                    "#   a    #",
                    "##########", 0 };

    cr_assert_eq(error_map_invalid_char(av), 84);
}