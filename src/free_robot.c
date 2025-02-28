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

int free_label(factory_t *robot)
{
    for (int i = 0; robot->label[i].offset != -1; i++){
        if (robot->label[i].label != NULL)
            free(robot->label[i].label);
    }
    free(robot->label);
    return 0;
}

int free_args(factarg_t *args)
{
    for (int i = 0; args[i].type != 0; i++){
        if (args[i].type == 1)
            free(args[i].label_name);
    }
    return 0;
}

int free_inst(factory_t *robot)
{
    for (int i = 0; robot->inst[i].opcode != 0; i++){
        free_args(robot->inst[i].args);
        free(robot->inst[i].args);
    }
    free(robot->inst);
    return 0;
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
        free_inst(robot);
    if (robot->label != NULL)
        free_label(robot);
    if (robot->output != NULL){
        free(robot->output->buffer);
        free(robot->output);
    }
    robot->input = NULL;
    robot->split = NULL;
    free(robot);
    robot = NULL;
    return ret_value;
}
