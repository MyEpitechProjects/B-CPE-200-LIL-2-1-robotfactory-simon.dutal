/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** minishell1
*/

#include "my_string.h"

char *my_strcpy(char *dest, char const *src)
{
    int index = 0;

    while (src[index] != '\0'){
        dest[index] = src[index];
        index += 1;
    }
    dest[index] = '\0';
    return dest;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int index = 0;

    while (src[index] != '\0' && index < n){
        dest[index] = src[index];
        index += 1;
    }
    dest[index] = '\0';
    return dest;
}
