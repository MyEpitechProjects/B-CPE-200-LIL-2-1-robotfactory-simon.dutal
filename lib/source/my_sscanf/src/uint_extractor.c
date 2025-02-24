/*
** EPITECH PROJECT, 2025
** my_sscanf
** File description:
** sscanf
*/

#include "my_sscanf.h"

INTERNAL void extract_uint(sscanf_t *sscanf)
{
    unsigned int number = 0;
    unsigned int *val;

    skip_space(sscanf);
    while (is_number(sscanf->string[sscanf->stringdx])){
        number += (sscanf->string[sscanf->stringdx] - 48);
        if (is_number(sscanf->string[sscanf->stringdx + 1]))
            number = number * 10;
        sscanf->stringdx += 1;
    }
    if (sscanf->ignore == 0){
        val = va_arg(sscanf->args, unsigned int *);
        *val = number;
    }
}

INTERNAL void extract_uint_long(sscanf_t *sscanf)
{
    unsigned long number = 0;
    unsigned long *val;

    skip_space(sscanf);
    while (is_number(sscanf->string[sscanf->stringdx])){
        number += (sscanf->string[sscanf->stringdx] - 48);
        if (is_number(sscanf->string[sscanf->stringdx + 1]))
            number = number * 10;
        sscanf->stringdx += 1;
    }
    if (sscanf->ignore == 0){
        val = va_arg(sscanf->args, unsigned long *);
        *val = number;
    }
}

INTERNAL void extract_uint_long_long(sscanf_t *sscanf)
{
    unsigned long long int number = 0;
    unsigned long long *val;

    skip_space(sscanf);
    while (is_number(sscanf->string[sscanf->stringdx])){
        number += (sscanf->string[sscanf->stringdx] - 48);
        if (is_number(sscanf->string[sscanf->stringdx + 1]))
            number = number * 10;
        sscanf->stringdx += 1;
    }
    if (sscanf->ignore == 0){
        val = va_arg(sscanf->args, unsigned long long *);
        *val = number;
    }
}

INTERNAL void extract_uint_short(sscanf_t *sscanf)
{
    unsigned short number = 0;
    unsigned short *val;

    skip_space(sscanf);
    while (is_number(sscanf->string[sscanf->stringdx])){
        number += (sscanf->string[sscanf->stringdx] - 48);
        if (is_number(sscanf->string[sscanf->stringdx + 1]))
            number = number * 10;
        sscanf->stringdx += 1;
    }
    if (sscanf->ignore == 0){
        val = va_arg(sscanf->args, unsigned short *);
        *val = number;
    }
}
