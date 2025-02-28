/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op.h
*/

#include "robot_factory.h"

int get_name(factory_t *robot)
{
    int ln = robot->idx + 1;
    int r = -1;

    if (my_list_len(robot->split) != 2 && r == -1)
        r = robot_err(robot, MISS_NAME, ln);
    if (robot->flg.header_end == 1 && r == -1)
        r = robot_err(robot, NAME_FIRST, ln);
    if (robot->flg.name_gived == 1 && r == -1)
        r = robot_err(robot, NAME_ONCE, ln);
    if (my_strlen(robot->split[1]) > PROG_NAME_LENGTH && r == -1)
        r = robot_err(robot, NAME_LONG, ln);
    if (r != -1)
        return 84;
    my_strcpy(robot->header.prog_name, robot->split[1]);
    robot->flg.name_gived = 1;
    robot->flg.file_empty = 0;
    return 0;
}

int get_comment(factory_t *robot)
{
    int ln = robot->idx + 1;
    int r = -1;

    if (r == -1 && my_list_len(robot->split) != 2)
        r = robot_err(robot, MISS_COMM, ln);
    if (r == -1 && robot->flg.comment_gived == 1)
        r = robot_err(robot, COMM_ONCE, ln);
    if (r == -1 && robot->flg.name_gived == 0)
        r = robot_err(robot, COMM_AFTER, ln);
    if (r == -1 && robot->flg.header_end == 1)
        r = robot_err(robot, MISS_COMM, ln);
    if (r == -1 && my_strlen(robot->split[1]) > COMMENT_LENGTH)
        r = robot_err(robot, COMM_LONG, ln);
    if (r != -1)
        return 84;
    my_strcpy(robot->header.comment, robot->split[1]);
    robot->flg.comment_gived = 1;
    robot->flg.file_empty = 0;
    return 0;
}

int extract_label(factory_t *robot)
{
    int len = my_strlen(robot->split[0]);
    char label[len - 1];

    my_strncpy(label, robot->split[0], len - 1);
    if (robot->split[0][len - 1] == LABEL_CHAR){
        if (!is_label_valid(label)){
            robot_err(robot, LAB_NAME, robot->idx + 1);
            return -1;
        }
        if (push_label(robot, label) == 84)
            return -1;
        return 1;
    }
    return 0;
}

int handle_line(factory_t *robot)
{
    int fix = 0;

    if (robot->split[0][0] == COMMENT_CHAR)
        return 0;
    if (!my_strcmp(robot->split[0], COMMENT_CMD_STRING))
        return get_comment(robot);
    if (!my_strcmp(robot->split[0], NAME_CMD_STRING))
        return get_name(robot);
    fix = extract_label(robot);
    if (fix == -1)
        return 84;
    if (my_list_len(robot->split) > (unsigned int) fix)
        return handle_inst(robot, fix);
    return 0;
}
