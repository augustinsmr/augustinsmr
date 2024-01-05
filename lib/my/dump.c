/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-secured-mathilde.lekens
** File description:
** dump.c
*/

#include "../../include/hashtable.h"

void ht_dump(hashtable_t *ht)
{
    int i = 0;
    hash_value_t *tmp;

    while (ht[i].index != -1) {
        tmp = ht[i].ht_values;
        my_putstr("[");
        my_put_nbr(ht[i].index);
        my_putstr("]:\n");
        while(tmp != NULL) {
            my_put_nbr(tmp->key);
            my_putstr(tmp->value);
            tmp = tmp->next;
        }
        i++;
    }
}