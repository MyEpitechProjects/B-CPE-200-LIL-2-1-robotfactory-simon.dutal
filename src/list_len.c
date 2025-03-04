/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** list_len
*/

#include "robot_factory.h"

//returns the number of instructions
int get_inst_list_len(factinst_t *tmp)
{
    int idx = 0;

    while (tmp[idx].opcode != 0)
        idx++;
    return idx + 1;
}

//TODO: comment
int get_label_list_len(factlab_t *tmp)
{
    int idx = 0;

    while (tmp[idx].offset >= 0)
        idx++;
    return idx + 1;
}
