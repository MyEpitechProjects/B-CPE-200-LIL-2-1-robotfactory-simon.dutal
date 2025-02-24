/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op.h
*/

#include "robot_factory.h"

unsigned long my_ftell(FILE *f)
{
    return f->_offset;
}

unsigned long get_lenght(FILE *f)
{
    unsigned long value = 0;

    fseek(f, 0, SEEK_END);
    value = my_ftell(f);
    fseek(f, 0, SEEK_SET);
    return value;
}

int ffclose(FILE *f, int ret_value)
{
    if (f != NULL)
        fclose(f);
    return ret_value;
}

int open_files(factory_t *robot, char **argv)
{
    FILE *in = fopen(argv[1], "rb");
    char *str;

    if (in == NULL)
        return 84;
    str = malloc(sizeof(char) * (get_lenght(in) + 1));
    if (str == NULL)
        return ffclose(in, 84);
    fread(str, 1, get_lenght(in), in);
    str[get_lenght(in)] = '\0';
    ffclose(in, 0);
    robot->input = my_split(str, "\n", '\0');
    free(str);
    return 0;
}
