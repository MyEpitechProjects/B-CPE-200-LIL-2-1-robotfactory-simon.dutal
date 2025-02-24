/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op.h
*/

#include "robot_factory.h"

static int init_robot_header(factory_t *robot)
{
    my_memset(&robot->header, sizeof(header_t), 0);
    robot->header.comment[0] = '\0';
    robot->header.prog_name[0] = '\0';
    robot->header.prog_size = 0;
    robot->header.magic = change_int_order(COREWAR_EXEC_MAGIC);
    return 0;
}

static int init_robot_inst(factory_t *robot)
{
    robot->inst = malloc(sizeof(factinst_t) * 1);
    if (robot->inst == NULL)
        return 84;
    robot->inst[0].encoding_byte = 0;
    robot->inst[0].opcode = 0;
    return 0;
}

static int init_robot_flg(factory_t *robot)
{
    robot->flg.comment_gived = 0;
    robot->flg.header_end = 0;
    robot->flg.name_gived = 0;
    robot->flg.file_empty = 1;
    if (init_robot_inst(robot) == 84)
        return 84;
    return 0;
}

int init_robot(int argc, char **argv, factory_t *robot)
{
    robot->offset = 0;
    robot->input = NULL;
    if (argc != 2)
        return 84;
    if (my_strlen(argv[1]) > 255)
        return 84;
    my_strcpy(robot->input_name, argv[1]);
    if (!my_strcmp(argv[1], "-h"))
        return help();
    if (open_files(robot, argv) == 84)
        return free_robot(robot, 84);
    robot->idx = 0;
    robot->split = NULL;
    init_robot_header(robot);
    if (init_robot_flg(robot) == 84)
        return free_robot(robot, 84);
    return 0;
}
