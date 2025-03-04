/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** robot_err
*/

#include "robot_factory.h"

const char *messages_err[] = {
    "The file is empty.\n",
    "No name specified.\n",
    "No comments specified.\n",
    "Syntax error.\n",
    "Invalid instruction.\n",
    "Invalid label name.\n",
    "Multiple definition of the same label.\n",
    "Invalid register number.\n",
    "The argument given to the instruction is invalid.\n",
    "Too many arguments given to the instruc tion.\n",
    "The name can only be defined once.\n",
    "The comment can only be defined once.\n",
    "The name of your program must be the first line.\n",
    "The program name is too long.\n",
    "The comment must be just after the name.\n",
    "The comment is too long.\n",
    "Undefined label.\n",
    NULL
};

//prints the corresponding error message
int robot_err(factory_t *robot, int message_id, int line)
{
    extern const char *messages_err[];

    my_puterr("\033[1;37m");
    my_puterr("asm, ");
    my_puterr(robot->input_name);
    if (line != 0){
        my_puterr(", line ");
        my_put_nbr_err(line);
    }
    my_puterr(": ");
    my_puterr("\033[1;36m");
    my_puterr(messages_err[message_id]);
    my_puterr("\033[0m");
    return 0;
}

//prints the corresponding warning message
int robot_warn(factory_t *robot, int message_id, int line)
{
    extern const char *messages_err[];

    my_puterr("\033[1;37m");
    my_puterr("asm, ");
    my_puterr(robot->input_name);
    my_puterr(", line ");
    my_put_nbr_err(line + 1);
    my_puterr(": ");
    my_puterr("\033[1;31m");
    my_puterr("Warning: ");
    my_puterr("\033[1;36m");
    my_puterr(messages_err[message_id]);
    my_puterr("\033[0m");
    return 0;
}

//TODO: comment
int check_err(factory_t *robot)
{
    if (robot->flg.file_empty == 1){
        robot_err(robot, EMPTY_FILE, 0);
        return (free_robot(robot, 84));
    }
    if (robot->flg.comment_gived == 0)
        robot_warn(robot, MISS_COMM, 1);
    return 0;
}
