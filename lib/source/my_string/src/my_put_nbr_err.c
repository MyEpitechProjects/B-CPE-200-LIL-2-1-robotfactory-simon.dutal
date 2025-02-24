/*
** EPITECH PROJECT, 2025
** my_sscanf
** File description:
** sscanf
*/

#include "my_string.h"

static void put_nbr_err_print_num(int nb, int nb2, int count, int special)
{
    char value = 0;

    for (int i = count; i > 0; i--){
        nb2 = nb;
        for (int t = 0; t < i - 1; t++){
            nb2 = nb2 / 10;
        }
        value = 48 + nb2 % 10;
        write(2, &value, 1);
    }
    if (special == 1){
        value = 48 + 8;
        write(2, &value, 1);
    }
}

int my_put_nbr_err(int nb)
{
    int nb2 = nb;
    int count = 1;
    int special = 0;

    if (nb < 0) {
        write(2, "-", 1);
        if (nb == -2147483648){
            nb = 214748364;
            special = 1;
        } else {
            nb = nb * -1;
        }
        nb2 = nb;
    }
    while (nb2 > 9){
        nb2 = nb2 / 10;
        count = count + 1;
    }
    put_nbr_err_print_num(nb, nb2, count, special);
    return 0;
}
