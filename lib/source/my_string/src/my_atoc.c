/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** minishell1
*/

#include "my_string.h"

char my_atoc(char const *str)
{
    char res = 0;
    int idx = 0;

    while (str[idx] != '\0' && my_char_is_int(str[idx])){
        res += (str[idx] - 48);
        if (my_char_is_int(str[idx + 1]))
            res = (res * 10);
        idx++;
    }
    return res;
}

unsigned char my_atouc(char const *str)
{
    unsigned char res = 0;
    int idx = 0;

    while (str[idx] != '\0' && my_char_is_int(str[idx])){
        res += (str[idx] - 48);
        if (my_char_is_int(str[idx + 1]))
            res = (res * 10);
        idx++;
    }
    return res;
}

int my_atoi(char const *str)
{
    int res = 0;
    int negative = (str[0] == '-');
    int idx = (negative == 1);

    while (str[idx] != '\0' && my_char_is_int(str[idx])){
        res += (str[idx] - 48);
        if (my_char_is_int(str[idx + 1]))
            res = (res * 10);
        idx++;
    }
    if (negative == 0)
        return res;
    else
        return res * -1;
}
