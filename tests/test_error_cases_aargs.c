/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-lenny.garnier
** File description:
** test_error_cases_aargs
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(error_cases_begining, test_ec_1)
{
    char *av[] = { "./my_sokoban", 0 };

    cr_assert_eq(error_cases_begining(1, av), 84);
}

Test(error_cases_begining, test_ec_2)
{
    char *av[] = { "./my_sokoban", "helloooo", 0 };

    cr_assert_eq(error_cases_begining(2, av), 84);
}