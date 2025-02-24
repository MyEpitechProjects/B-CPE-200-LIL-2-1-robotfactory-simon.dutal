/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** op.h
*/

#ifndef _ALL_LIB_
    #define _ALL_LIB_
int my_sscanf(char *string, char *format, ...);
int my_strlen(const char *str);
int my_puterr(const char *str);
char **my_split(char *text, char *delim, char spe);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(char *dest, char *input);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
void my_memset(void *ptr, int size, char value);
int my_string_is_int(const char *str);
int my_putstr(const char *str);
#endif
