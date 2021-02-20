/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-lenny.garnier
** File description:
** test_is_char_correct
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(is_char_correct, error_char_1)
{
    cr_assert_eq(is_char_correct('a'), 0);
}

Test(is_char_correct, error_char_2)
{
    cr_assert_eq(is_char_correct('P'), 1);
}