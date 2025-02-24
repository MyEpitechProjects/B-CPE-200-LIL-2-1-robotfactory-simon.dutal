/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op.h
*/

#include "robot_factory.h"

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

int get_inst_list_len(factinst_t *tmp)
{
    int idx = 0;

    while (tmp[idx].opcode != 0)
        idx++;
    return idx + 1;
}

int push_inst(factory_t *robot, int opcode, int encoding_byte)
{
    int len = get_inst_list_len(robot->inst);

    robot->inst = secure_realloc(robot->inst, sizeof(factinst_t) * (len + 1));
    if (robot->inst == NULL)
        return 84;
    robot->inst[len].encoding_byte = 0;
    robot->inst[len].opcode = 0;
    robot->inst[len - 1].encoding_byte = encoding_byte;
    robot->inst[len - 1].opcode = opcode;
    return 0;
}
