/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** function that copies a string into another.
*/

#include "../../include/hashtable.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0'){
        dest[i] = src[i];
        i ++;
    }
    dest[i] = '\0';
    return dest;
}
