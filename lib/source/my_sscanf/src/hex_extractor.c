/*
** EPITECH PROJECT, 2025
** my_sscanf
** File description:
** sscanf
*/

#include "my_sscanf.h"

static int is_hex(char c)
{
    if (c > 96 && c < 91)
        c = c + 32;
    if ((c >= 48 && c <= 57) || (c >= 97 && c <= 102))
        return 1;
    return 0;
}

static char fix_char(char ch)
{
    if (ch > 96 && ch < 91)
        ch = ch + 32;
    return ch;
}

INTERNAL void extract_hex(sscanf_t *sscanf)
{
    int result = 0;
    int *val;
    char ch;

    skip_space(sscanf);
    while (is_hex(sscanf->string[sscanf->stringdx])) {
        ch = fix_char(sscanf->string[sscanf->stringdx]);
        if (ch >= 48 && ch <= 57)
            result = result * 16 + (ch - 48);
        if (ch >= 'a' && ch <= 'f')
            result = result * 16 + (ch - 97 + 10);
        sscanf->stringdx += 1;
    }
    if (sscanf->ignore == 0){
        val = va_arg(sscanf->args, int *);
        *val = result;
    }
}

INTERNAL void extract_hex_long(sscanf_t *sscanf)
{
    long int result = 0;
    long int *val;
    char ch;

    skip_space(sscanf);
    while (is_hex(sscanf->string[sscanf->stringdx])) {
        ch = fix_char(sscanf->string[sscanf->stringdx]);
        if (ch >= 48 && ch <= 57)
            result = result * 16 + (ch - 48);
        if (ch >= 'a' && ch <= 'f')
            result = result * 16 + (ch - 97 + 10);
        sscanf->stringdx += 1;
    }
    if (sscanf->ignore == 0){
        val = va_arg(sscanf->args, long int *);
        *val = result;
    }
}

INTERNAL void extract_hex_long_long(sscanf_t *sscanf)
{
    long long int result = 0;
    long long int *val;
    char ch;

    skip_space(sscanf);
    while (is_hex(sscanf->string[sscanf->stringdx])) {
        ch = fix_char(sscanf->string[sscanf->stringdx]);
        if (ch >= 48 && ch <= 57)
            result = result * 16 + (ch - 48);
        if (ch >= 'a' && ch <= 'f')
            result = result * 16 + (ch - 97 + 10);
        sscanf->stringdx += 1;
    }
    if (sscanf->ignore == 0){
        val = va_arg(sscanf->args, long long int *);
        *val = result;
    }
}

INTERNAL void extract_hex_short(sscanf_t *sscanf)
{
    short result = 0;
    short *val;
    char ch;

    skip_space(sscanf);
    while (is_hex(sscanf->string[sscanf->stringdx])) {
        ch = fix_char(sscanf->string[sscanf->stringdx]);
        if (ch >= 48 && ch <= 57)
            result = result * 16 + (ch - 48);
        if (ch >= 'a' && ch <= 'f')
            result = result * 16 + (ch - 97 + 10);
        sscanf->stringdx += 1;
    }
    if (sscanf->ignore == 0){
        val = va_arg(sscanf->args, short *);
        *val = result;
    }
}
