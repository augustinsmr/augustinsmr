/*
** EPITECH PROJECT, 2023
** B-CPE-110-LIL-1-1-secured-mathilde.lekens
** File description:
** delete.c
*/

#include "../../include/hashtable.h"

void delete_hashtable(hashtable_t *ht)
{
    int i = 0;
    hash_value_t *tmp;
    hash_value_t *tmp2;

    while (ht[i].index != -1) {
        tmp = ht[i].ht_values;
        while (tmp != NULL) {
            tmp2 = tmp->next;
            free(tmp->value);
            free(tmp);
            tmp = tmp2;
        }
        i ++;
    }
    free(tmp);
    free(tmp2);
    free(ht);
}
