/*
** EPITECH PROJECT, 2025
** my_sscanf
** File description:
** sscanf
*/

#include "my_sscanf.h"

static void choose_float(sscanf_t *sscanf)
{
    if (sscanf->flg_modifier == 0)
        extract_float(sscanf);
    if (sscanf->flg_modifier == 2)
        extract_double(sscanf);
    if (sscanf->flg_modifier == 3)
        extract_double_long(sscanf);
}

static void choose_uint(sscanf_t *sscanf)
{
    if (sscanf->flg_modifier == 0)
        extract_uint(sscanf);
    if (sscanf->flg_modifier == 1)
        extract_uint_short(sscanf);
    if (sscanf->flg_modifier == 2)
        extract_uint_long(sscanf);
    if (sscanf->flg_modifier == 3)
        extract_uint_long_long(sscanf);
    if (sscanf->flg_modifier == 5)
        extract_uint_size_t(sscanf);
}

static void choose_int(sscanf_t *sscanf)
{
    if (sscanf->flg_modifier == 0)
        extract_int(sscanf);
    if (sscanf->flg_modifier == 1)
        extract_int_short(sscanf);
    if (sscanf->flg_modifier == 2)
        extract_int_long(sscanf);
    if (sscanf->flg_modifier == 3)
        extract_int_long_long(sscanf);
    if (sscanf->flg_modifier == 4)
        extract_int_intmax_t(sscanf);
    if (sscanf->flg_modifier == 6)
        extract_int_ptrdiff_t(sscanf);
}

static void choose_hex(sscanf_t *sscanf)
{
    if (sscanf->flg_modifier == 0)
        extract_hex(sscanf);
    if (sscanf->flg_modifier == 1)
        extract_hex_short(sscanf);
    if (sscanf->flg_modifier == 2)
        extract_hex_long(sscanf);
    if (sscanf->flg_modifier == 3)
        extract_hex_long_long(sscanf);
}

static void choose_special_string(sscanf_t *sscanf, int max)
{
    char *str = NULL;

    if (sscanf->format[sscanf->formatdx + 1] == '^'){
        sscanf->formatdx += 2;
        str = get_sub_string(sscanf);
        extract_string_until(sscanf, max, str);
    } else {
        sscanf->formatdx += 1;
        str = get_sub_string(sscanf);
        extract_string_while(sscanf, max, str);
    }
    if (str != NULL)
        free(str);
}

INTERNAL void choose_flg(sscanf_t *sscanf)
{
    int max = sscanf->max;
    char c = sscanf->format[sscanf->formatdx];

    if (c == 's')
        extract_string(sscanf, max);
    if (c == 'd' || c == 'i')
        choose_int(sscanf);
    if (c == 'f')
        choose_float(sscanf);
    if (c == 'x' || c == 'X')
        choose_hex(sscanf);
    if (c == 'c')
        extract_char(sscanf);
    if (c == 'u')
        choose_uint(sscanf);
    if (c == '[')
        choose_special_string(sscanf, max);
}
