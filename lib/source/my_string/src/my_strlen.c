/*
** EPITECH PROJECT, 2025
** my_sscanf
** File description:
** sscanf
*/

#include "my_string.h"

int my_strlen(const char *str)
{
    int idx = 0;

    while (str[idx] != '\0')
        idx++;
    return idx;
}
