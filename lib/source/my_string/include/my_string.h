/*
** EPITECH PROJECT, 2025
** mylib
** File description:
** header
*/

#ifndef LIBSTR_H
    #define LIBSTR_H
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>


int my_strlen(const char *str);
int my_puterr(const char *str);
char **my_split(const char *text, const char *delim, const char spe);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(char *dest, char *input);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
void my_memset(void *ptr, int size, char value);
int my_put_nbr_err(int nb);
int my_string_is_int(const char *str);
bool my_char_is_int(char c);
char my_atoc(char const *str);
unsigned char my_atouc(char const *str);
int my_atoi(char const *str);

#endif
