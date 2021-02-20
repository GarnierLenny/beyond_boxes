/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-lenny.garnier
** File description:
** test_char_to_str
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(char_to_str, test_char_to_str)
{
    cr_assert_str_eq(char_to_str('a'), "a");
}