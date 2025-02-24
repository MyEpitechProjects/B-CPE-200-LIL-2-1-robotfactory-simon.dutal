/*
** EPITECH PROJECT, 2025
** my_sscanf
** File description:
** sscanf
*/

#include "my_sscanf.h"

INTERNAL void extract_int(sscanf_t *sscanf)
{
    int number = 0;
    int *val;

    skip_space(sscanf);
    while (is_number(sscanf->string[sscanf->stringdx])){
        number += (sscanf->string[sscanf->stringdx] - 48);
        if (is_number(sscanf->string[sscanf->stringdx + 1]))
            number = number * 10;
        sscanf->stringdx += 1;
    }
    if (sscanf->ignore == 0){
        val = va_arg(sscanf->args, int *);
        *val = number;
    }
}

INTERNAL void extract_int_long(sscanf_t *sscanf)
{
    long int number = 0;
    long int *val;

    skip_space(sscanf);
    while (is_number(sscanf->string[sscanf->stringdx])){
        number += (sscanf->string[sscanf->stringdx] - 48);
        if (is_number(sscanf->string[sscanf->stringdx + 1]))
            number = number * 10;
        sscanf->stringdx += 1;
    }
    if (sscanf->ignore == 0){
        val = va_arg(sscanf->args, long int *);
        *val = number;
    }
}

INTERNAL void extract_int_long_long(sscanf_t *sscanf)
{
    long long int number = 0;
    long long int *val;

    skip_space(sscanf);
    while (is_number(sscanf->string[sscanf->stringdx])){
        number += (sscanf->string[sscanf->stringdx] - 48);
        if (is_number(sscanf->string[sscanf->stringdx + 1]))
            number = number * 10;
        sscanf->stringdx += 1;
    }
    if (sscanf->ignore == 0){
        val = va_arg(sscanf->args, long long int *);
        *val = number;
    }
}

INTERNAL void extract_int_short(sscanf_t *sscanf)
{
    short number = 0;
    short *val;

    skip_space(sscanf);
    while (is_number(sscanf->string[sscanf->stringdx])){
        number += (sscanf->string[sscanf->stringdx] - 48);
        if (is_number(sscanf->string[sscanf->stringdx + 1]))
            number = number * 10;
        sscanf->stringdx += 1;
    }
    if (sscanf->ignore == 0){
        val = va_arg(sscanf->args, short *);
        *val = number;
    }
}

INTERNAL void skip_space(sscanf_t *sscanf)
{
    for (int i = sscanf->stringdx;
        (is_end_str(sscanf->string[sscanf->stringdx])); i++)
        sscanf->stringdx += 1;
}
