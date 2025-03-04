/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** write_output
*/

#include "robot_factory.h"

//TODO: comment all these horrors beyond my comprehension
int get_ext_lenght(factory_t *robot)
{
    int has_point = 0;
    int idx = 0;
    int len = 0;

    while (robot->input_name[idx] != '\0') {
        if (robot->input_name[idx] == '.') {
            len = 0;
            has_point = 1;
        } else
            len += 1;
        idx++;
    }
    if (has_point == 0)
        return 0;
    if (robot->input_name[idx - 1] == '.')
        return 1;
    return len + 1;
}

//creates and open the output file
FILE *create_file(factory_t *robot)
{
    int len = get_ext_lenght(robot);
    int filename_len = (my_strlen(robot->input_name) - len);
    char filename[filename_len + 5];
    FILE *f = NULL;

    my_strncpy(filename, robot->input_name, filename_len);
    my_strcat(filename, ".cor");
    f = fopen(filename, "wb");
    return f;
}

short get_label_offset(factlab_t *lab, char *label)
{
    for (int i = 0; lab[i].offset != -1; i++) {
        if (lab[i].label == NULL)
            continue;
        if (!my_strcmp(lab[i].label, label))
            return lab[i].offset;
    }
    return -1;
}

static int write_one_arg(factory_t *robot, factarg_t arg)
{
    int tmp = 0;

    if (arg.type == 1) {
        tmp = get_label_offset(robot->label, arg.label_name);
        if (tmp == -1) {
            robot_err(robot, UNDEF_LABEL, 0);
            return -1;
        }
        tmp = (tmp - robot->offset);
        return swrite_w_rev(&tmp, sizeof(short), robot->output);
    }
    if (arg.type == 2)
        return swrite_w_rev(&arg.short_val, sizeof(short), robot->output);
    if (arg.type == 3)
        return swrite_w_rev(&arg.int_val, sizeof(int), robot->output);
    if (arg.type == 4)
        return swrite_w_rev(&arg.char_val, sizeof(char), robot->output);
    return -1;
}

int write_args(factory_t *robot, factarg_t *arg)
{
    int noffset = 0;

    for (int i = 0; arg[i].type != 0; i++) {
        noffset += write_one_arg(robot, arg[i]);
    }
    return noffset;
}

static int write_inst(factory_t *robot)
{
    int noffset = 0;
    int tmp = 0;

    for (int i = 0; robot->inst[i].opcode != 0; i++) {
        noffset = 0;
        noffset += swrite_write(&robot->inst[i].opcode,
            sizeof(char), robot->output);
        if (robot->inst[i].encoding_byte != -1) {
            swrite_write(&robot->inst[i].encoding_byte, sizeof(char),
            robot->output);
            noffset += 1;
        }
        tmp = write_args(robot, robot->inst[i].args);
        if (tmp < 0)
            return 84;
        noffset += tmp;
        robot->offset += (noffset);
    }
    return 0;
}

int write_output(factory_t *robot)
{
    FILE *f;

    robot->header.prog_size = change_int_order(robot->offset);
    robot->output = swrite_init(8 + PROG_NAME_LENGTH
    + COMMENT_LENGTH + robot->offset + 30);
    if (robot->output == NULL) {
        return free_robot(robot, 84);
    }
    swrite_write(&robot->header, sizeof(header_t), robot->output);
    robot->offset = 0;
    if (write_inst(robot) == 84)
        return free_robot(robot, 84);
    f = create_file(robot);
    if (f != NULL) {
        swrite_to_file(robot->output, f);
        fclose(f);
    } else
        return free_robot(robot, 84);
    return free_robot(robot, 0);
}
