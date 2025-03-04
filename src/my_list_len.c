/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** my_list_len
*/

#include "robot_factory.h"

//returns the len of value array
unsigned int my_list_len(char **value)
{
    unsigned int idx = 0;

    while (value[idx] != NULL)
        idx++;
    return idx;
}
