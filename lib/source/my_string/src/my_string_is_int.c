/*
** EPITECH PROJECT, 2025
** my_sscanf
** File description:
** sscanf
*/

#include "my_string.h"

int my_string_is_int(const char *str)
{
    int start = 0;

    if (str == NULL)
        return 0;
    if (str[0] == '-' || str[0] == '+')
        start = 1;
    for (int i = start; str[i] != '\0'; i++){
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}
