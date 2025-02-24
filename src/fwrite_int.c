/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op.h
*/

#include "robot_factory.h"

int change_int_order(unsigned int num)
{
    int result = 0;

    for (int i = 0; i < 4; i++) {
        result = (result | ((num >> (i * 8)) & 0xFF) <<
            (((sizeof(num)-1) - i) * 8));
    }
    return result;
}
