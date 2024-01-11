/*
** EPITECH PROJECT, 2024
** secured
** File description:
** ht_delete.c
*/

#include "../../include/hashtable.h"

void delete_node_inht(hash_value_t **temp,
    hash_value_t **value, hash_value_t **prev)
{
    if (*prev == NULL) {
        *value = (*value)->next;
    } else {
        (*prev)->next = (*temp)->next;
    }
}

int search_linked_list_del(hash_value_t **value, int hashed_key)
{
    hash_value_t *temp = *value;
    hash_value_t *prev = NULL;

    while (temp) {
        if (temp->key == hashed_key) {
            delete_node_inht(&temp, value, &prev);
            return 1;
        }
        prev = temp;
        temp = temp->next;
    }
    return 0;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int len_ht = retrieve_length(ht);
    int hashed_key;
    int i = 0;

    if (len_ht == 0 || key == NULL)
        return 84;
    hashed_key = ht->hash(key, len_ht);
    while (ht[i].index != -1) {
        if (search_linked_list_del(&(ht[i].ht_values), hashed_key) == 1)
            return 0;
        i ++;
    }
    return 84;
}
