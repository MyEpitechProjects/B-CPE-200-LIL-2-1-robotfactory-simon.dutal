/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** swrite
*/

#include "robot_factory.h"

swrite_t *swrite_init(int size)
{
    swrite_t *writer = malloc(sizeof(swrite_t));

    if (writer == NULL)
        return NULL;
    writer->size = size;
    writer->buffer = malloc(size);
    if (writer->buffer == NULL){
        free(writer);
        return NULL;
    }
    writer->pos = 0;
    return writer;
}

int swrite_write(void *buffer, int size, swrite_t *fd)
{
    int old_pos = fd->pos;

    if ((fd->pos + size) >= fd->size)
        return -1;
    for (int i = 0; i < size; i++){
        ((char *)fd->buffer)[fd->pos] = ((char *)buffer)[i];
        fd->pos += 1;
    }
    return fd->pos - old_pos;
}

int swrite_w_rev(void *buffer, int size, swrite_t *fd)
{
    int old_pos = fd->pos;

    if ((fd->pos + size) >= fd->size)
        return -1;
    for (int i = size - 1; i >= 0; i--){
        ((char *)fd->buffer)[fd->pos] = ((char *)buffer)[i];
        fd->pos += 1;
    }
    return fd->pos - old_pos;
}

int swrite_to_file(swrite_t *fd, FILE *fd2)
{
    return fwrite(fd->buffer, fd->pos, 1, fd2);
}
