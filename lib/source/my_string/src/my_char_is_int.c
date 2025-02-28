/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** minishell1
*/

#include "my_string.h"

bool my_char_is_int(char c)
{
    if (c < '0' || c > '9')
        return false;
    return true;
}
