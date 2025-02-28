/*
** EPITECH PROJECT, 2025
** my_sscanf
** File description:
** sscanf
*/

#include "my_sscanf.h"

void extract_float(sscanf_t *sscanf)
{
    float value[] = {0, 0};
    float *val;
    int len = 0;

    skip_space(sscanf);
    value[0] = get_number(sscanf);
    if (sscanf->string[sscanf->stringdx] == '.')
        sscanf->stringdx += 1;
    len = get_number_len(sscanf);
    for (int i = sscanf->stringdx + len - 1; i >= sscanf->stringdx; i--)
        value[1] = (value[1] + (sscanf->string[i] - 48)) * 0.10;
    sscanf->stringdx += len;
    if (sscanf->ignore == 0){
        val = va_arg(sscanf->args, float *);
        *val = (value[0] + value[1]);
    }
}

void extract_double(sscanf_t *sscanf)
{
    double value[] = {0, 0};
    double *val;
    int len = 0;

    skip_space(sscanf);
    value[0] = (double) get_number(sscanf);
    if (sscanf->string[sscanf->stringdx] == '.')
        sscanf->stringdx += 1;
    len = get_number_len(sscanf);
    for (int i = sscanf->stringdx + len - 1; i >= sscanf->stringdx; i--)
        value[1] = (value[1] + (sscanf->string[i] - 48)) * 0.10;
    sscanf->stringdx += len;
    if (sscanf->ignore == 0){
        val = va_arg(sscanf->args, double *);
        *val = (value[0] + value[1]);
    }
}

void extract_double_long(sscanf_t *sscanf)
{
    long double value[] = {0, 0};
    long double *val;
    int len = 0;

    skip_space(sscanf);
    value[0] = (long double) get_number_long(sscanf);
    if (sscanf->string[sscanf->stringdx] == '.')
        sscanf->stringdx += 1;
    len = get_number_len(sscanf);
    for (int i = sscanf->stringdx + len - 1; i >= sscanf->stringdx; i--)
        value[1] = (value[1] + (sscanf->string[i] - 48)) * 0.10;
    sscanf->stringdx += len;
    if (sscanf->ignore == 0){
        val = va_arg(sscanf->args, long double *);
        *val = (value[0] + value[1]);
    }
}
