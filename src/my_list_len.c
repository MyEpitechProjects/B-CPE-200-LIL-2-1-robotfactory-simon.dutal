/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op.h
*/

#include "robot_factory.h"


unsigned int my_list_len(char **value)
{
    unsigned int idx = 0;

    while (value[idx] != NULL)
        idx++;
    return idx;
}
