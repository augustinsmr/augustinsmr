/*
** EPITECH PROJECT, 2024
** secured
** File description:
** create_ht.c
*/

#include "../../include/hashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = malloc((len + 1) * sizeof(hashtable_t));

    if (len <= 0)
        return NULL;
    ht[0].hash = hash;
    ht[0].index = -1;
    ht[0].ht_values = NULL;
    for (int i = 0; i < len; i ++) {
        ht[i].hash = hash;
        ht[i].index = i;
        ht[i].ht_values = NULL;
    }
    ht[len].index = -1;
    return ht;
}
