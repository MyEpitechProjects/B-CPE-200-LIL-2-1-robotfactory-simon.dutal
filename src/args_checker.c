/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op.h
*/

#include "robot_factory.h"

int get_args_type(char *arg)
{
    char c = 0;

    my_sscanf(arg, "%1s", &c);
    if (c == 'r')
        return T_REG;
    if (c == '%')
        return T_DIR;
    if (c == ':')
        return T_IND;
    return -1;
}

int check_arg(factory_t *robot, op_t inst, int fix)
{
    int my_arg = -1;

    for (int i = fix; robot->split[i] != NULL; i++){
        my_arg = get_args_type(robot->split[i]);
        if (my_arg == -1 ||
            !is_arg_possible(my_arg, inst.type[i - fix])){
            robot_err(robot, BAD_ARG, robot->idx + 1);
            return 84;
        }
    }
    return 0;
}

bool is_arg_possible(char arg, char possible_arg)
{
    if ((possible_arg & arg) == arg)
        return true;
    return false;
}

char get_encoding_byte(op_t inst, factory_t *robot, int fix)
{
    int value = 6;
    int res = 0;

    if (inst.nbr_args < 2)
        return -1;
    for (int i = fix; robot->split[i] != NULL; i++){
        res += (get_args_type(robot->split[i]) << value);
        value = value - 2;
    }
    return res;
}
