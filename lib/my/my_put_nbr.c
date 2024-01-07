/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-secured-mathilde.lekens
** File description:
** my_put_nbr.c
*/

#include "../../include/hashtable.h"

int my_put_nbr(int nb)
{
    long int nb2 = nb;

    if (nb2 < 0) {
        nb2 *= -1;
        my_putchar('-');
    }
    if (nb2 >= 10) {
        my_put_nbr(nb2 / 10);
        my_putchar(nb2 % 10 + 48);
    } else {
        my_putchar(nb2 + 48);
    }
}
