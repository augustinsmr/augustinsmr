/*
** EPITECH PROJECT, 2024
** secured
** File description:
** insert_ht.c
*/

#include "../../include/hashtable.h"

int retrieve_length(hashtable_t *ht)
{
    int i = 0;

    while (ht[i].index != -1)
        i ++;
    return i;
}

void append_node(hashtable_t *ht, int key, char *value)
{
    hash_value_t *new = malloc(sizeof(hash_value_t));
    int len_value = my_strlen(value);
    hash_value_t *temp = ht->ht_values;

    new->value = malloc(sizeof(char) * (len_value + 1));
    my_strcpy(new->value, value);
    new->key = key;
    if (ht->ht_values == NULL) {
        ht->ht_values = new;
        new->next = NULL;
    } else {
        new->next = temp;
        ht->ht_values = new;
    }
}

int store(int hashed_key, int len_ht)
{
    int temp = hashed_key;
    int i = 0;
    int boup = 1;

    while (temp > 0) {
        temp /= 10;
        i ++;
    }
    temp = hashed_key;
    for (int j = 0; j < i; j ++) {
        temp /= 10;
        if (j % 2 == 0 && temp % 10 != 0)
            boup *= (temp % 10);
    }
    return (hashed_key - boup) % len_ht;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int len_ht = retrieve_length(ht);
    int hashed_key;
    int storing_place;
    int error = 84;

    if (len_ht == 0)
        return 84;
    hashed_key = ht->hash(key, len_ht);
    storing_place = store(hashed_key, len_ht);
    for (int i = 0; i < len_ht; i ++) {
        if (ht[i].index == storing_place) {
            append_node(&(ht[i]), hashed_key, value);
            error = 0;
        }
    }
    return error;
}
