/*
** EPITECH PROJECT, 2025
** my_sscanf
** File description:
** sscanf
*/

#include "my_string.h"

int my_puterr(const char *str)
{
    if (str == NULL)
        return 0;
    return write(2, str, my_strlen(str));
}
