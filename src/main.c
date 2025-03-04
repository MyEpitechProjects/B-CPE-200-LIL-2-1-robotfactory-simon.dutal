/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** main
*/

#include "robot_factory.h"

//prints the help message
int help(char **argv, int silent, int ret_value)
{
    if (silent == 0)
        my_putstr("USAGE\n");
    if (silent == 1)
        my_putstr("Usage: ");
    my_putstr(argv[0]);
    my_putstr(" file_name[.s] ....\n");
    if (silent == 0){
        my_putstr("DESCRIPTION\n");
        my_putstr("file_name file in assembly ");
        my_putstr("language to be converted into ");
        my_putstr("file_name.cor, ");
        my_putstr("an executable in the ");
        my_putstr("Virtual Machine.\n");
    }
    return ret_value;
}

//start robot extracting
int start(factory_t *robot)
{
    int x = 0;
    char delimiter[] = "\t  ";

    delimiter[2] = SEPARATOR_CHAR;
    if (robot->input == NULL)
        return 0;
    for (robot->idx = 0; robot->input[robot->idx] != NULL; robot->idx++){
        robot->split = my_split(robot->input[robot->idx], delimiter, '"');
        if (robot->split == NULL)
            continue;
        x = handle_line(robot);
        if (x == 84)
            return free_robot(robot, 84);
        free_list(robot->split, 0);
        robot->split = NULL;
    }
    return 0;
}

//robot script for each file in program command
int robot_loop(char **argv, int argv_idx)
{
    int x = 0;
    factory_t *robot = malloc(sizeof(factory_t));

    if (robot == NULL)
        return 84;
    if (init_robot(argv_idx, argv, robot) == 84)
        return 84;
    x = start(robot);
    if (x == 84)
        return 84;
    x = check_err(robot);
    if (x == 84)
        return 84;
    return write_output(robot);
}

//checks and goes through all the arguments,
//displaying the help and transcribing the valid files
int main(int argc, char **argv)
{
    int x = 0;
    int x2 = 0;

    if (argc < 2)
        return help(argv, 1, 84);
    if (!my_strcmp(argv[1], "-h"))
        return help(argv, 0, 0);
    for (int i = 1; i < argc; i++){
        x2 = robot_loop(argv, i);
        if (x2 == 84)
            x = 84;
    }
    return x;
}
