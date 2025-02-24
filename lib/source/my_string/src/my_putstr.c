/*
** EPITECH PROJECT, 2025
** my_sscanf
** File description:
** sscanf
*/

#include "my_string.h"

int my_putstr(const char *str)
{
    if (str == NULL)
        return 0;
    return write(1, str, my_strlen(str));
}
