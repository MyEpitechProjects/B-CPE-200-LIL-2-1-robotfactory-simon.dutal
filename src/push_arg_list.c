/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** push_arg_list
*/

#include "robot_factory.h"

// get arg value type based on his type and instruction
static int get_arg_value_type(char *arg, int type, char inst)
{
    if (type == 1)
        return REG_CHAR;
    if (type == 2){
        if (arg[1] == LABEL_CHAR)
            return DIR_LAB;
        if (is_dir_size_2(inst) == 2)
            return DIR_SHORT;
        else
            return DIR_INT;
    }
    if (type == 4){
        if (arg[0] == LABEL_CHAR)
            return IND_LAB;
        else
            return IND_SHORT;
    }
    return 0;
}

// push short value in instruction args list
static void push_arg_short(char *arg, factarg_t *args, int i, int fix)
{
    int res;
    int fixed = 0;

    if (arg[0] == DIRECT_CHAR)
        fixed += 1;
    res = my_atoi(arg + fixed);
    args[(i - fix)].short_val = (short) res;
}

// push label (string) value in instruction args list
static void push_arg_lab(char *arg, factarg_t args[], int i, int fix)
{
    int fixed = 0;

    if (arg[0] == LABEL_CHAR)
        fixed += 1;
    if (arg[0] == DIRECT_CHAR)
        fixed += 2;
    args[(i - fix)].label_name = malloc(sizeof(char) *
        (my_strlen(arg + fixed) + 1));
    if (args[(i - fix)].label_name != NULL)
        my_strcpy(args[(i - fix)].label_name, arg + fixed);
}

// push int value in instruction args list
static void push_arg_int(char *arg, factarg_t *args, int i, int fix)
{
    int res = my_atoi(arg + 1);

    args[(i - fix)].int_val = res;
}

// push char value in instruction args list
static void push_arg_char(char *arg, factarg_t *args, int i, int fix)
{
    char res = my_atouc(arg + 1);

    args[(i - fix)].char_val = res;
}

// push args value in instruction args list
void extract_args(factory_t *robot, factarg_t *args, int fix, char inst)
{
    int type = -1;

    for (int i = fix; robot->split[i] != NULL; i++){
        type = get_arg_value_type(robot->split[i],
            get_args_type(robot->split[i]), inst);
        args[(i - fix)].type = type;
        if (type == REG_CHAR)
            push_arg_char(robot->split[i], args, i, fix);
        if (type == DIR_LAB || type == IND_LAB)
            push_arg_lab(robot->split[i], args, i, fix);
        if (type == DIR_SHORT || type == IND_SHORT)
            push_arg_short(robot->split[i], args, i, fix);
        if (type == DIR_INT)
            push_arg_int(robot->split[i], args, i, fix);
        args[(i - fix) + 1].type = 0;
    }
}
