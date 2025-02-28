/*
** EPITECH PROJECT, 2025
** my_sscanf
** File description:
** sscanf
*/

#include "my_sscanf.h"

static int c_in_str(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == c)
            return 1;
    }
    return 0;
}

static int calcul_string_spe_len(sscanf_t *sscanf, char *str,
    int data[], int mode)
{
    int len = 0;

    if (mode == 0)
        for (int i = sscanf->stringdx;
            !(c_in_str(str, sscanf->string[sscanf->stringdx]))
            && ((data[0] + i) < data[1] || data[1] == 0)
            && sscanf->string[i] != '\0'; i++){
            len += 1;
            sscanf->stringdx += 1;
        }
    if (mode == 1)
        for (int i = sscanf->stringdx;
            c_in_str(str, sscanf->string[sscanf->stringdx])
            && ((data[0] + i) < data[1] || data[1] == 0)
            && sscanf->string[i] != '\0'; i++){
            len += 1;
            sscanf->stringdx += 1;
        }
    return len;
}

static int calcul_string_len(sscanf_t *sscanf, int l, int max)
{
    int len = 0;

    for (int i = sscanf->stringdx;
        !(is_end_str(sscanf->string[sscanf->stringdx]))
        && ((l + i) < max || max == 0); i++){
        len += 1;
        sscanf->stringdx += 1;
    }
    return len;
}

static char *load_string_arg(sscanf_t *sscanf)
{
    char *str = NULL;

    if (sscanf->ignore == 0){
        str = va_arg(sscanf->args, char *);
        str[0] = '\0';
        return str;
    }
    return NULL;
}

void extract_string(sscanf_t *sscanf, int max)
{
    int len = 0;
    char *s = load_string_arg(sscanf);
    int l = 0;

    skip_space(sscanf);
    l = sscanf->stringdx;
    len = calcul_string_len(sscanf, l, max);
    sscanf->stringdx = l;
    for (int i = sscanf->stringdx; i < l + len; i++){
        if (sscanf->ignore == 0)
            s[i - l] = sscanf->string[sscanf->stringdx];
        sscanf->stringdx += 1;
    }
    if (sscanf->ignore == 0)
        s[len] = '\0';
}

void extract_char(sscanf_t *sscanf)
{
    char *s;
    char c;

    for (int i = sscanf->stringdx;
        (is_end_str(sscanf->string[sscanf->stringdx])); i++)
        sscanf->stringdx += 1;
    c = sscanf->string[sscanf->stringdx];
    sscanf->stringdx += 1;
    if (sscanf->ignore == 0){
        s = va_arg(sscanf->args, char *);
        *s = c;
    }
}

static int get_sub_string_len(sscanf_t *sscanf)
{
    int count = 0;
    int i = sscanf->formatdx;

    while (sscanf->format[i] != ']' && sscanf->format[i] != '\0'){
        count = count + 1;
        i = i + 1;
    }
    return count;
}

char *get_sub_string(sscanf_t *sscanf)
{
    int count = get_sub_string_len(sscanf);
    char *res = malloc(sizeof(char) * (count + 1));
    int i = sscanf->formatdx;
    int idx = 0;

    if (res == NULL)
        return NULL;
    while ((sscanf->format[i] != ']') && (sscanf->format[i] != '\0')){
        res[idx] = sscanf->format[i];
        sscanf->formatdx += 1;
        i += 1;
        idx += 1;
    }
    res[count] = '\0';
    return res;
}

void extract_string_until(sscanf_t *sscanf, int max, char *str)
{
    int len = 0;
    char *s = load_string_arg(sscanf);
    int l = 0;

    if (str == NULL)
        return;
    l = sscanf->stringdx;
    len = calcul_string_spe_len(sscanf, str, (int[]) {l, max}, 0);
    sscanf->stringdx = l;
    for (int i = sscanf->stringdx; i < l + len; i++){
        if (sscanf->ignore == 0)
            s[i - l] = sscanf->string[sscanf->stringdx];
        sscanf->stringdx += 1;
    }
    if (sscanf->ignore == 0)
        s[len] = '\0';
}

void extract_string_while(sscanf_t *sscanf, int max, char *str)
{
    int len = 0;
    char *s = load_string_arg(sscanf);
    int l = 0;

    if (str == NULL)
        return;
    l = sscanf->stringdx;
    len = calcul_string_spe_len(sscanf, str, (int[]) {l, max}, 0);
    sscanf->stringdx = l;
    for (int i = sscanf->stringdx; i < l + len; i++){
        if (sscanf->ignore == 0)
            s[i - l] = sscanf->string[sscanf->stringdx];
        sscanf->stringdx += 1;
    }
    if (sscanf->ignore == 0)
        s[len] = '\0';
}
