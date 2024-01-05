/*
** EPITECH PROJECT, 2024
** secured
** File description:
** create_ht.c
*/

#include "../../include/hashtable.h"

hash_value_t *new_node()
{
    hash_value_t *new = malloc(sizeof(hash_value_t *));

    new->next = NULL;
    return new;
}

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ht = malloc((len + 1) * sizeof(hashtable_t));

    for (int i = 0; i < len; i ++) {
        ht[i].hash = hash;
        ht[i].index = i;
        ht[i].ht_values = NULL;
    }
    ht[len].index = -1;
    return ht;
}
