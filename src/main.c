/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op.h
*/

#include "robot_factory.h"


int help(void)
{
    return 0;
}

int start(factory_t *robot)
{
    int x = 0;

    if (robot->input == NULL)
        return 0;
    for (robot->idx = 0; robot->input[robot->idx] != NULL; robot->idx++){
        robot->split = my_split(robot->input[robot->idx], "\t ", '"');
        if (robot->split == NULL)
            continue;
        x = handle_line(robot);
        if (x == 84)
            return 84;
        free_list(robot->split, 0);
        robot->split = NULL;
    }
    return 0;
}

int main(int argc, char **argv)
{
    int x = 0;
    factory_t *robot = malloc(sizeof(factory_t));

    if (robot == NULL)
        return 84;
    if (init_robot(argc, argv, robot) == 84)
        return 84;
    x = start(robot);
    if (x == 84)
        return 84;
    x = check_err(robot);
    if (x == 84)
        return 84;
    return write_output(robot);
}
