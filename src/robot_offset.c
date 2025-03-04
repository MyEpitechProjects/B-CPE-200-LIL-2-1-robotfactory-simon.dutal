/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** robot_offset
*/

#include "robot_factory.h"

//TODO: comment
char is_dir_size_2(char inst)
{
    char inst_code[] = {9, 10, 11, 12, 14, 15, 0};

    for (int i = 0; inst_code[i] != 0; i++){
        if (inst_code[i] == inst)
            return 2;
    }
    return 4;
}

//returns the byte size of the data type?
void get_type_size(factory_t *robot, char type, char inst)
{
    if (type == 1)
        robot->offset += 1;
    if (type == 2)
        robot->offset += is_dir_size_2(inst);
    if (type == 4)
        robot->offset += 2;
}
