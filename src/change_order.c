/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** change_order
*/

#include "robot_factory.h"

//returns a bit reversed int
int change_int_order(int num)
{
    int result = 0;

    for (int i = 0; i < 4; i++) {
        result = (result | ((num >> (i * 8)) & 0xFF) <<
            (((sizeof(num) -1) - i) * 8));
    }
    return result;
}

//returns a bit reversed short
int change_short_order(short num)
{
    short result = 0;

    for (int i = 0; i < 2; i++) {
        result = (result | ((num >> (i * 8)) & 0xFF) <<
            (((sizeof(num) -1) - i) * 8));
    }
    return result;
}
