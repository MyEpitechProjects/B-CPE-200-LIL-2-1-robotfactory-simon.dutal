/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op.h
*/

#include "robot_factory.h"

int compute_inst(factory_t *robot, op_t inst)
{
    int fix = 1;

    if (my_list_len(robot->split) - fix > (unsigned int) inst.nbr_args){
        robot_err(robot, MANY_ARG, robot->idx + 1);
        return 84;
    }
    if (check_arg(robot, inst, fix) == 84)
        return 84;
    push_inst(robot, inst.code, get_encoding_byte(inst, robot, fix));
    return 0;
}

int handle_inst(factory_t *robot)
{
    extern const op_t op_tab[];

    robot->flg.header_end = 1;
    for (int i = 0; op_tab[i].code != 0; i++){
        if (!my_strcmp(op_tab[i].mnemonique, robot->split[0]))
            return compute_inst(robot, op_tab[i]);
    }
    robot_err(robot, BAD_INST, robot->idx + 1);
    return 84;
}
