/*
** EPITECH PROJECT, 2025
** my_sscanf
** File description:
** sscanf
*/

#include "my_sscanf.h"

INTERNAL int my_strlen(char *c)
{
    int idx = 0;

    while (c[idx] != '\0')
        idx++;
    return idx;
}

INTERNAL int free_struct(sscanf_t *sscanf, int retval)
{
    if (sscanf->string != NULL)
        free(sscanf->string);
    if (sscanf->format != NULL)
        free(sscanf->format);
    va_end(sscanf->args);
    free(sscanf);
    return retval;
}

INTERNAL int init_sscanf(sscanf_t *sscanf, char *string, char *format)
{
    if (sscanf == NULL)
        return 84;
    sscanf->string = NULL;
    sscanf->format = NULL;
    if (string == NULL || format == NULL ||
        string[0] == '\0' || format[0] == '\0')
        return free_struct(sscanf, 84);
    sscanf->stringlen = my_strlen(string);
    sscanf->formatlen = my_strlen(format);
    sscanf->stringdx = 0;
    sscanf->formatdx = 0;
    sscanf->string = malloc(sizeof(char) * (my_strlen(string) + 1));
    sscanf->format = malloc(sizeof(char) * (my_strlen(format) + 1));
    if (sscanf->string == NULL || sscanf->format == NULL)
        return free_struct(sscanf, 84);
    strcpy(sscanf->string, string);
    strcpy(sscanf->format, format);
    return 0;
}

int my_sscanf(char *string, char *format, ...)
{
    sscanf_t *sscanf = malloc(sizeof(sscanf_t));
    int v = init_sscanf(sscanf, string, format);

    if (v == 84)
        return 84;
    va_start(sscanf->args, format);
    while (sscanf->formatdx < sscanf->formatlen){
        if (format[sscanf->formatdx] == '%'){
            handle_flg(sscanf);
            continue;
        }
        if (format[sscanf->formatdx] != '%' &&
            format[sscanf->formatdx] != string[sscanf->stringdx])
            break;
        else {
            sscanf->stringdx += 1;
            sscanf->formatdx += 1;
        }
    }
    return free_struct(sscanf, 0);
}
