/*
** EPITECH PROJECT, 2025
** my_sscanf
** File description:
** sscanf
*/

#include "my_sscanf.h"

INTERNAL void extract_int_intmax_t(sscanf_t *sscanf)
{
    intmax_t number = 0;
    intmax_t *val;

    for (int i = sscanf->stringdx;
        (is_end_str(sscanf->string[sscanf->stringdx])); i++)
        sscanf->stringdx += 1;
    while (is_number(sscanf->string[sscanf->stringdx])){
        number += (sscanf->string[sscanf->stringdx] - 48);
        if (is_number(sscanf->string[sscanf->stringdx + 1]))
            number = number * 10;
        sscanf->stringdx += 1;
    }
    if (sscanf->ignore == 0){
        val = va_arg(sscanf->args, intmax_t *);
        *val = number;
    }
}

INTERNAL void extract_int_ptrdiff_t(sscanf_t *sscanf)
{
    ptrdiff_t number = 0;
    ptrdiff_t *val;

    for (int i = sscanf->stringdx;
        (is_end_str(sscanf->string[sscanf->stringdx])); i++)
        sscanf->stringdx += 1;
    while (is_number(sscanf->string[sscanf->stringdx])){
        number += (sscanf->string[sscanf->stringdx] - 48);
        if (is_number(sscanf->string[sscanf->stringdx + 1]))
            number = number * 10;
        sscanf->stringdx += 1;
    }
    if (sscanf->ignore == 0){
        val = va_arg(sscanf->args, ptrdiff_t *);
        *val = number;
    }
}

INTERNAL void extract_uint_size_t(sscanf_t *sscanf)
{
    size_t number = 0;
    size_t *val;

    for (int i = sscanf->stringdx;
        (is_end_str(sscanf->string[sscanf->stringdx])); i++)
        sscanf->stringdx += 1;
    while (is_number(sscanf->string[sscanf->stringdx])){
        number += (sscanf->string[sscanf->stringdx] - 48);
        if (is_number(sscanf->string[sscanf->stringdx + 1]))
            number = number * 10;
        sscanf->stringdx += 1;
    }
    if (sscanf->ignore == 0){
        val = va_arg(sscanf->args, size_t *);
        *val = number;
    }
}
