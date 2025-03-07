/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** handle_line
*/

#include "robot_factory.h"

//pushes the parsed name and comment to the data structs
static int push_data(factory_t *robot, int mode, char *name, int r)
{
    if (r != -1)
        return 84;
    robot->flg.file_empty = 0;
    if (mode == 0){
        robot->header.prog_name[0] = '\0';
        robot->flg.name_gived = 1;
    }
    if (mode == 1) {
        robot->header.comment[0] = '\0';
        robot->flg.comment_gived = 1;
    }
    if (mode == 2){
        my_strcpy(robot->header.prog_name, name);
        robot->flg.name_gived = 1;
    }
    if (mode == 3) {
        my_strcpy(robot->header.comment, robot->split[1]);
        robot->flg.comment_gived = 1;
    }
    return 0;
}

//returns false if the name or comment is empty
static bool is_name_comment_empty(factory_t *robot)
{
    char **split = my_split(robot->input[robot->idx], "\t, ", '\0');
    bool res = false;

    if (split == NULL)
        return false;
    if (my_list_len(split) < 2)
        return false;
    if (my_strcmp(split[1], "\"\"") == 0)
        res = true;
    free_list(split, 0);
    return res;
}

//checks for syntax error in name
static bool is_syntax_err(factory_t *robot)
{
    char **split = my_split(robot->input[robot->idx], "\t, ", '\0');
    int res = 0;
    int len = 0;

    if (split == NULL)
        return 0;
    len = my_list_len(split);
    if (len < 2)
        return 0;
    if (split[1][0] != '"' ||
        split[len - 1][my_strlen(split[len - 1]) - 1] != '"')
        res = 1;
    free_list(split, 0);
    return res;
}

//push name if valid
int get_name(factory_t *robot)
{
    int ln = robot->idx + 1;
    int r = -1;

    if (r == -1 && robot->flg.header_end == 1)
        r = robot_err(robot, NAME_FIRST, ln);
    if (r == -1 && robot->flg.name_gived == 1)
        r = robot_err(robot, NAME_ONCE, ln);
    if (is_name_comment_empty(robot))
        return push_data(robot, 0, NULL, r);
    if (r == -1 && is_syntax_err(robot))
        r = robot_err(robot, SYNTAX_ERR, ln);
    if (r == -1 && my_list_len(robot->split) != 2)
        r = robot_err(robot, MISS_NAME, ln);
    if (r == -1 && my_strlen(robot->split[1]) > PROG_NAME_LENGTH)
        r = robot_err(robot, NAME_LONG, ln);
    if (r != -1)
        return 84;
    return push_data(robot, 2, robot->split[1], r);
}

//push comment if valid
int get_comment(factory_t *robot)
{
    int ln = robot->idx + 1;
    int r = -1;

    if (r == -1 && robot->flg.comment_gived == 1)
        r = robot_err(robot, COMM_ONCE, ln);
    if (r == -1 && robot->flg.name_gived == 0)
        r = robot_err(robot, COMM_AFTER, ln);
    if (r == -1 && is_name_comment_empty(robot))
        return push_data(robot, 1, NULL, r);
    if (r == -1 && is_syntax_err(robot))
        r = robot_err(robot, SYNTAX_ERR, ln);
    if (r == -1 && my_list_len(robot->split) != 2)
        r = robot_err(robot, MISS_COMM, ln);
    if (r == -1 && robot->flg.header_end == 1)
        r = robot_err(robot, MISS_COMM, ln);
    if (r == -1 && my_strlen(robot->split[1]) > COMMENT_LENGTH)
        r = robot_err(robot, COMM_LONG, ln);
    if (r != -1)
        return 84;
    return push_data(robot, 3, robot->split[1], r);
}

//extract and push a label if valid
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

//handles a line
//stops the program in case of bad line
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
