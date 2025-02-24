/*
** EPITECH PROJECT, 2025
** mylib
** File description:
** header
*/

#ifndef LIBMY_H
    #define LIBMY_H
    #ifdef __GNUC__
        #define INTERNAL __attribute__((visibility("hidden")))
    #endif
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

#endif
