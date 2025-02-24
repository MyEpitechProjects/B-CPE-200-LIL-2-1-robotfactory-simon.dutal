/*
** EPITECH PROJECT, 2025
** my_sscanf
** File description:
** sscanf
*/

#include "my_sscanf.h"

static void extract_flg_modifier_two(sscanf_t *sscanf, char *str)
{
    if (str[0] == 'h' && str[1] == 'h')
        sscanf->flg_modifier = 0;
    if (str[0] == 'l' && str[1] == 'l')
        sscanf->flg_modifier = 3;
}

static void extract_flg_modifier_one(sscanf_t *sscanf, char c)
{
    if (c == 'l')
        sscanf->flg_modifier = 2;
    if (c == 'j')
        sscanf->flg_modifier = 4;
    if (c == 'z')
        sscanf->flg_modifier = 5;
    if (c == 't')
        sscanf->flg_modifier = 6;
    if (c == 'L')
        sscanf->flg_modifier = 7;
}

INTERNAL void extract_flg_modifier(sscanf_t *sscanf)
{
    char str[3];

    sscanf->flg_modifier = 0;
    if (is_flg(sscanf->format[sscanf->formatdx]))
        return;
    if (is_flg(sscanf->format[sscanf->formatdx + 1])){
        extract_flg_modifier_one(sscanf, sscanf->format[sscanf->formatdx]);
        sscanf->formatdx += 1;
    } else {
        str[2] = '\0';
        str[0] = sscanf->format[sscanf->formatdx];
        str[1] = sscanf->format[sscanf->formatdx + 1];
        sscanf->formatdx += 2;
        extract_flg_modifier_two(sscanf, str);
    }
}
