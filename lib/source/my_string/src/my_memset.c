/*
** EPITECH PROJECT, 2025
** my_sscanf
** File description:
** sscanf
*/

#include "my_string.h"

void my_memset(void *ptr, int size, char value)
{
    if (ptr == NULL)
        return;
    for (int i = 0; i < size; i++)
        ((char *)ptr)[i] = value;
}
