/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op.h
*/

#include "robot_factory.h"

size_t fwrite_byte(FILE *f, char c)
{
    return fwrite(&c, sizeof(c), 1, f);
}

size_t fwrite_bytes(FILE *f, int size, char *c)
{
    return fwrite(c, size, 1, f);
}

size_t fwrite_bytes_fixedl(FILE *f, int size, char *c, int fix_size)
{
    char x = '\0';
    size_t size_written = 0;

    size_written += fwrite(c, size, 1, f);
    if (fix_size < size)
        return size_written;
    for (int i = 0; i < (fix_size - size); i++)
        size_written += fwrite(&x, 1, 1, f);
    return size_written;
}
