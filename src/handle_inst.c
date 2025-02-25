/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op.h
*/

#include "robot_factory.h"

int compute_inst(factory_t *robot, op_t inst, int fixed)
{
    int fix = 0;

    if (fixed == 0)
        fix = 1;
    else if (fixed == 1)
        fix = 2;
    if (my_list_len(robot->split) - fix > (unsigned int) inst.nbr_args){
        robot_err(robot, MANY_ARG, robot->idx + 1);
        return 84;
    }
    if (check_arg(robot, inst, fix) == 84)
        return 84;
    push_inst(robot, inst.code, get_encoding_byte(inst, robot, fix));
    return 0;
}

int handle_inst(factory_t *robot, int fix)
{
    extern const op_t op_tab[];

    robot->flg.header_end = 1;
    for (int i = 0; op_tab[i].code != 0; i++){
        if (!my_strcmp(op_tab[i].mnemonique, robot->split[fix]))
            return compute_inst(robot, op_tab[i], fix);
    }
    robot_err(robot, BAD_INST, robot->idx + 1);
    return 84;
}
