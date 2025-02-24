/*
** EPITECH PROJECT, 2025
** my_sscanf
** File description:
** sscanf
*/

#include "my_sscanf.h"

INTERNAL int is_flg(char c)
{
    if (c == 'd' || c == 'i' || c == 'x' || c == 'X' ||
        c == 'c' || c == 'f' || c == 'u' ||
        c == 's' || c == '[')
        return 1;
    return 0;
}

INTERNAL int is_number(char c)
{
    return (c >= 48 && c <= 57);
}

INTERNAL int is_end_str(char c)
{
    if (c == '\t' || c == ' ' || c == '\0')
        return 1;
    return 0;
}

INTERNAL void extract_flg(sscanf_t *sscanf)
{
    int max = 0;

    while (is_number(sscanf->format[sscanf->formatdx])){
        max += (sscanf->format[sscanf->formatdx] - 48);
        if (is_number(sscanf->format[sscanf->formatdx + 1]))
            max = max * 10;
        sscanf->formatdx += 1;
    }
    sscanf->max = max;
    extract_flg_modifier(sscanf);
    choose_flg(sscanf);
}

INTERNAL void handle_flg(sscanf_t *sscanf)
{
    sscanf->ignore = 0;
    sscanf->formatdx += 1;
    if (sscanf->format[sscanf->formatdx] == '%'
        && sscanf->string[sscanf->stringdx] == '%'){
        sscanf->stringdx += 1;
        sscanf->formatdx += 1;
        return;
    }
    if (sscanf->format[sscanf->formatdx] == '*'){
        sscanf->ignore = 1;
        sscanf->formatdx += 1;
    }
    extract_flg(sscanf);
    sscanf->formatdx += 1;
}
