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

    if (ht == NULL)
        return;
    while (ht[i].index != -1) {
        tmp = ht[i].ht_values;
        write(1, "[", 1);
        my_put_nbr(ht[i].index);
        write(1, "]:\n", 3);
        while (tmp != NULL) {
            write(1, "> ", 2);
            my_put_nbr(tmp->key);
            write(1, " - ", 3);
            write(1, tmp->value, my_strlen(tmp->value));
            tmp = tmp->next;
            write(1, "\n", 1);
        }
        i++;
    }
}
