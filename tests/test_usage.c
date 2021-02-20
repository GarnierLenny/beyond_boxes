/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-lenny.garnier
** File description:
** test_usage
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(usage, test_usage_1)
{
    char *av[] = { "./my_sokoban", "-h", 0 };

    cr_assert_eq(usage(2, av), 1);
}

Test(usage, test_usage_2)
{
    char *av[] = { "./my_sokoban", "map", 0 };

    cr_assert_eq(usage(2, av), 0);
}