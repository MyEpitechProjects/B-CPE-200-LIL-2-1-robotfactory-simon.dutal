/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** list_push
*/

#include "robot_factory.h"

//realloc with security wrapper
//TODO: why is this here?
void *secure_realloc(void *pointer, size_t size)
{
    void *tmp = pointer;

    pointer = realloc(pointer, size);
    if (pointer == NULL){
        free(tmp);
        return NULL;
    }
    return pointer;
}

//TODO: comments
int push_inst(factory_t *robot, int opcode, int encoding_byte, factarg_t *args)
{
    int len = get_inst_list_len(robot->inst);

    robot->inst = secure_realloc(robot->inst, sizeof(factinst_t) * (len + 1));
    if (robot->inst == NULL)
        return 84;
    robot->inst[len].encoding_byte = 0;
    robot->inst[len].opcode = 0;
    robot->inst[len - 1].encoding_byte = encoding_byte;
    robot->inst[len - 1].opcode = opcode;
    robot->inst[len - 1].args = args;
    return 0;
}

int push_label(factory_t *robot, char *label)
{
    int len = get_label_list_len(robot->label);
    char *label_string = NULL;

    if (get_label_offset(robot->label, label) != -1){
        robot_err(robot, LAB_DEF, robot->idx + 1);
        return 84;
    }
    label_string = malloc(sizeof(char) * (my_strlen(label) + 1));
    if (label_string == NULL)
        return 84;
    robot->label = secure_realloc(robot->label, sizeof(factlab_t) * (len + 1));
    if (robot->label == NULL)
        return my_free(label_string, 84);
    my_strcpy(label_string, label);
    robot->label[len].label = NULL;
    robot->label[len].offset = -1;
    robot->label[len - 1].offset = robot->offset;
    robot->label[len - 1].label = label_string;
    return 0;
}
