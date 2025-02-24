/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op.h
*/

#include "robot_factory.h"

int free_list(char **lst, int ret_value)
{
    if (lst == NULL)
        return ret_value;
    for (int i = 0; lst[i] != NULL; i++)
        free(lst[i]);
    free(lst);
    return ret_value;
}

int free_robot(factory_t *robot, int ret_value)
{
    if (robot == NULL)
        return ret_value;
    if (robot->input != NULL)
        free_list(robot->input, 0);
    if (robot->split != NULL)
        free_list(robot->split, 0);
    if (robot->inst != NULL)
        free(robot->inst);
    robot->input = NULL;
    robot->split = NULL;
    free(robot);
    robot = NULL;
    return ret_value;
}
