/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-secured-mathilde.lekens
** File description:
** my_putstr.c
*/

#include "../../include/hashtable.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}
