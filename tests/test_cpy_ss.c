/*
** EPITECH PROJECT, 2021
** B-PSU-200-RUN-2-1-mysokoban-lenny.garnier
** File description:
** test_cpy_ss
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(cpy_ss, test_copy_ss)
{
    char *av[] = { "Hello", "World", "toto", 0 };
    char **buffer = cpy_ss(av);

    cr_assert_str_eq(buffer[1], "World");
}