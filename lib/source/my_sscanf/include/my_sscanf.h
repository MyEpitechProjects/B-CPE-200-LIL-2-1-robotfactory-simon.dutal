/*
** EPITECH PROJECT, 2025
** mylib
** File description:
** header
*/

#ifndef LIBSCANF_H
    #define LIBSCANF_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <string.h>
    #include <stdarg.h>
    #include <inttypes.h>

typedef struct sscanf {
    char *string;
    char *format;
    int formatdx;
    int stringdx;
    int stringlen;
    int formatlen;
    int ignore;
    int flg_modifier;
    int max;
    va_list args;
} sscanf_t;

void choose_flg(sscanf_t *sscanf);
void extract_flg_modifier(sscanf_t *sscanf);
void extract_float(sscanf_t *sscanf);
void extract_double(sscanf_t *sscanf);
void extract_double_long(sscanf_t *sscanf);
void extract_hex(sscanf_t *sscanf);
void extract_hex_long(sscanf_t *sscanf);
void extract_hex_long_long(sscanf_t *sscanf);
void extract_hex_short(sscanf_t *sscanf);
void extract_int_short(sscanf_t *sscanf);
void extract_int_long_long(sscanf_t *sscanf);
void extract_int_long(sscanf_t *sscanf);
void extract_int(sscanf_t *sscanf);
int is_flg(char c);
int is_number(char c);
int is_end_str(char c);
void extract_flg(sscanf_t *sscanf);
void handle_flg(sscanf_t *sscanf);
int free_struct(sscanf_t *sscanf, int retval);
int init_sscanf(sscanf_t *sscanf, char *string, char *format);
int my_sscanf(char *string, char *format, ...);
void extract_uint(sscanf_t *sscanf);
void extract_uint_long(sscanf_t *sscanf);
void extract_uint_long_long(sscanf_t *sscanf);
void extract_uint_short(sscanf_t *sscanf);
void extract_int_intmax_t(sscanf_t *sscanf);
void extract_int_ptrdiff_t(sscanf_t *sscanf);
void extract_uint_size_t(sscanf_t *sscanf);
void extract_char(sscanf_t *sscanf);
void extract_string(sscanf_t *sscanf, int max);
int get_number_len(sscanf_t *sscanf);
int get_number(sscanf_t *sscanf);
int get_number_long(sscanf_t *sscanf);
int get_number_long_long(sscanf_t *sscanf);
void extract_string_while(sscanf_t *sscanf, int max, char *str);
void extract_string_until(sscanf_t *sscanf, int max, char *str);
char *get_sub_string(sscanf_t *sscanf);
void skip_space(sscanf_t *sscanf);

#endif
