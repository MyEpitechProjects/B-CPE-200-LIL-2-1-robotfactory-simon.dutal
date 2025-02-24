/*
** EPITECH PROJECT, 2025
** my_sscanf
** File description:
** sscanf
*/

#include "my_sscanf.h"

INTERNAL int get_number_len(sscanf_t *sscanf)
{
    int res = 0;

    for (int i = sscanf->stringdx; is_number(sscanf->string[i]); i++)
        res += 1;
    return res;
}

INTERNAL int get_number(sscanf_t *sscanf)
{
    int res = 0;

    while (is_number(sscanf->string[sscanf->stringdx])){
        res += (sscanf->string[sscanf->stringdx] - 48);
        if (is_number(sscanf->string[sscanf->stringdx + 1]))
            res = res * 10;
        sscanf->stringdx += 1;
    }
    return res;
}

INTERNAL int get_number_long(sscanf_t *sscanf)
{
    long res = 0;

    while (is_number(sscanf->string[sscanf->stringdx])){
        res += (sscanf->string[sscanf->stringdx] - 48);
        if (is_number(sscanf->string[sscanf->stringdx + 1]))
            res = res * 10;
        sscanf->stringdx += 1;
    }
    return res;
}

INTERNAL int get_number_long_long(sscanf_t *sscanf)
{
    long long res = 0;

    while (is_number(sscanf->string[sscanf->stringdx])){
        res += (sscanf->string[sscanf->stringdx] - 48);
        if (is_number(sscanf->string[sscanf->stringdx + 1]))
            res = res * 10;
        sscanf->stringdx += 1;
    }
    return res;
}
