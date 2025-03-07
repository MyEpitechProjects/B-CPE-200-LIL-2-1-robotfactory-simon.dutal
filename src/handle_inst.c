/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** handle_inst
*/

#include "robot_factory.h"

//allocs a array of stucts to store the args data
static factarg_t *create_args_list(void)
{
    factarg_t *args = malloc(sizeof(factarg_t) * 5);

    if (args == NULL)
        return NULL;
    args[0].type = 0;
    return args;
}

//check args
static int check(factory_t *robot, op_t inst, int fix)
{
    if (my_list_len(robot->split) - fix > (unsigned int) inst.nbr_args){
        robot_err(robot, MANY_ARG, robot->idx + 1);
        return 84;
    }
    if (my_list_len(robot->split) - fix < (unsigned int) inst.nbr_args){
        robot_err(robot, FEW_ARG, robot->idx + 1);
        return 84;
    }
    if (check_arg(robot, inst, fix) == 84)
        return 84;
    return 0;
}

//extract and push instruction/args
//causes the program to stop in case of bad argument(s)
int compute_inst(factory_t *robot, op_t inst, int fixed)
{
    int fix = 0;
    int res = 0;
    factarg_t *args = create_args_list();

    if (args == NULL)
        return 84;
    if (fixed == 0)
        fix = 1;
    else if (fixed == 1)
        fix = 2;
    if (check(robot, inst, fix) == 84){
        free(args);
        return 84;
    }
    extract_args(robot, args, fix, inst.code);
    robot->offset += 1;
    res = push_inst(robot, inst.code,
        get_encoding_byte(inst, robot, fix), args);
    return res;
}

//handles the instruction and its arguments,
//prints an error and causes the program to stop
//in case of bad instruction or argument(s)
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
