/*
** EPITECH PROJECT, 2024
** secured
** File description:
** search_ht.c
*/

#include "../../include/hashtable.h"

char *search_linked_list(hash_value_t *value, int hashed_key)
{
    hash_value_t *temp = value;

    while (temp) {
        if (temp->key == hashed_key) {
            return temp->value;
        }
        temp = temp->next;
    }
    return NULL;
}

char *ht_search(hashtable_t *ht, char *key)
{
    int len_ht = retrieve_length(ht);
    int hashed_key;
    int i = 0;
    char *value;

    if (len_ht == 0)
        return 0;
    hashed_key = ht->hash(key, len_ht);
    while (ht[i].index != -1) {
        value = search_linked_list(ht[i].ht_values, hashed_key);
        if (value != NULL)
            return value;
        i ++;
    }
    return "not found";
}
