/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op.h
*/

#include "robot_factory.h"

static bool is_labal_char_valid(char l)
{
    char *str = LABEL_CHARS;

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == l)
            return true;
    }
    return false;
}

bool is_label_valid(char *label)
{
    if (label == NULL || my_strlen(label) < 1)
        return false;
    for (int i = 0; label[i] != '\0'; i++){
        if (!is_labal_char_valid(label[i]))
            return false;
    }
    return true;
}

static int verify_reg(char *arg)
{
    int val = 0;

    if (!my_string_is_int(arg))
        return -2;
    my_sscanf(arg, "%d", &val);
    if (val <= REG_NUMBER && val > 0)
        return T_REG;
    return -2;
}

int get_args_type(char *arg)
{
    char c[] = "  ";

    if (my_strlen(arg) < 2)
        return -1;
    my_sscanf(arg, "%c%c", &c[0], &c[1]);
    if (c[0] == 'r')
        return verify_reg(arg + 1);
    if (c[0] == DIRECT_CHAR){
        if (c[1] == LABEL_CHAR)
            return T_DIR;
        if (my_string_is_int(arg + 1))
            return T_DIR;
    }
    if (c[0] == LABEL_CHAR)
        return T_IND;
    if (my_string_is_int(arg))
        return T_IND;
    return -1;
}

int check_arg(factory_t *robot, op_t inst, int fix)
{
    int my_arg = -1;

    for (int i = fix; robot->split[i] != NULL; i++){
        my_arg = get_args_type(robot->split[i]);
        if (my_arg < 0){
            robot_err(robot, 9 + my_arg, robot->idx + 1);
            return 84;
        }
        if (!is_arg_possible(my_arg, inst.type[i - fix])){
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
    int type = 0;
    int arg_type = 0;

    for (int i = fix; robot->split[i] != NULL; i++){
        type = inst.type[i - fix];
        arg_type = get_args_type(robot->split[i]);
        if (arg_type == 4)
            arg_type = 3;
        if ((type != 2 && type != 4)){
            res += (arg_type << value);
            value = value - 2;
        }
    }
    if (res == 0)
        return -1;
    return res;
}
