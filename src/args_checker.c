/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op.h
*/

#include "robot_factory.h"

static bool is_good_separator(char *arg)
{
    int already = 0;

    for (int i = 0; arg[i] != '\0'; i++){
        if (arg[i] == SEPARATOR_CHAR)
            already = 1;
        if (arg[i] != SEPARATOR_CHAR &&
            already == 1)
            return false;
    }
    return true;
}

static int verify_number(char *arg)
{
    char *str = malloc(sizeof(char) * (my_strlen(arg) + 1));
    char res = 0;

    if (str == NULL)
        return 0;
    my_sscanf(arg, "%[^, ]", str);
    res = my_string_is_int(str);
    free(str);
    return res;
}

static int verify_reg(char *arg)
{
    int val = 0;

    if (!verify_number(arg))
        return -2;
    my_sscanf(arg, "%d", &val);
    if (val <= REG_NUMBER)
        return 0;
    return -2;
}

int get_args_type(char *arg)
{
    char c[] = "  ";

    if (my_strlen(arg) < 2)
        return -1;
    if (is_good_separator(arg) == 0)
        return -1;
    my_sscanf(arg, "%c%c", &c[0], &c[1]);
    if (c[0] == 'r')
        return verify_reg(arg + 1);
    if (c[0] == '%'){
        if (c[1] == ':')
            return T_DIR;
        if (verify_number(arg + 1))
            return T_DIR;
    }
    if (c[0] == ':')
        return T_IND;
    if (verify_number(arg))
        return T_IND;
    return -1;
}

int check_arg(factory_t *robot, op_t inst, int fix)
{
    int my_arg = -1;

    for (int i = fix; robot->split[i] != NULL; i++){
        my_arg = get_args_type(robot->split[i]);
        if (my_arg < 0 ||
            !is_arg_possible(my_arg, inst.type[i - fix])){
            robot_err(robot, 9 + my_arg, robot->idx + 1);
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

    if (inst.nbr_args < 2)
        return -1;
    for (int i = fix; robot->split[i] != NULL; i++){
        res += (get_args_type(robot->split[i]) << value);
        value = value - 2;
    }
    return res;
}
