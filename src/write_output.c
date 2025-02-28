/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op.h
*/

#include "robot_factory.h"

int get_ext_lenght(factory_t *robot)
{
    int has_point = 0;
    int idx = 0;
    int len = 0;

    while (robot->input_name[idx] != '\0'){
        if (robot->input_name[idx] == '.'){
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

static int write_inst(factory_t *robot)
{
    for (int i = 0; robot->inst[i].opcode != 0; i++){
        swrite_write(&robot->inst[i].opcode, sizeof(char), robot->output);
        if (robot->inst[i].encoding_byte != -1)
            swrite_write(&robot->inst[i].encoding_byte, sizeof(char),
                robot->output);
    }
    return 0;
}

int write_output(factory_t *robot)
{
    FILE *f = create_file(robot);

    robot->header.prog_size = change_int_order(robot->offset);
    if (f == NULL)
        return free_robot(robot, 84);
    robot->output = swrite_init(8 + PROG_NAME_LENGTH +
        COMMENT_LENGTH + robot->offset);
    if (robot->output == NULL){
        fclose(f);
        return free_robot(robot, 84);
    }
    swrite_write(&robot->header, sizeof(header_t), robot->output);
    write_inst(robot);
    swrite_to_file(robot->output, f);
    fclose(f);
    return free_robot(robot, 0);
}
