/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** open_files
*/

#include "robot_factory.h"

//gets and returns the position in the file
unsigned long my_ftell(FILE *f)
{
    long offset = f->_offset;

    if (offset < 0)
        return 0;
    return offset;
}

//returns the lenght of the file's content
unsigned long get_lenght(FILE *f)
{
    unsigned long value = 0;

    fseek(f, 0, SEEK_END);
    value = my_ftell(f);
    fseek(f, 0, SEEK_SET);
    return value;
}

//closes the file
int ffclose(FILE *f, int ret_value)
{
    if (f != NULL)
        fclose(f);
    return ret_value;
}

//open, reads and starts parsing the file's content
int open_files(factory_t *robot)
{
    FILE *in = fopen(robot->input_name, "rb");
    char *str;

    if (in == NULL)
        return 84;
    str = malloc(sizeof(char) * (get_lenght(in) + 1));
    if (str == NULL)
        return ffclose(in, 84);
    fread(str, 1, get_lenght(in), in);
    str[get_lenght(in)] = '\0';
    ffclose(in, 0);
    robot->input = my_pysplit(str, '\n');
    free(str);
    return 0;
}
