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

void change_node(hash_value_t *ht, int hashed_key, char *value)
{
    int i = 0;
    hash_value_t *temp = ht;

    while (temp != NULL) {
        if (ht->key == hashed_key) {
            free(ht->value);
            ht->value = malloc(sizeof(char) * (my_strlen(ht->value) + 1));
            my_strcpy(ht->value, value);
            return;
        }
        temp = temp->next;
        i ++;
    }
}

void insert_next(hashtable_t *ht, int check, int hashed_key, char *value)
{
    if (check == 1)
        append_node((ht), hashed_key, value);
    else
        change_node((*ht).ht_values, hashed_key, value);
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int len_ht = retrieve_length(ht);
    int hashed_key;
    int storing_place;
    int error = 84;

    if (len_ht == 0 || key == NULL || value == NULL)
        return 84;
    hashed_key = ht->hash(key, len_ht);
    storing_place = hashed_key % len_ht;
    for (int i = 0; i < len_ht; i ++) {
        if (ht[i].index == storing_place) {
            insert_next(&ht[i], (ht_search(ht, key) == NULL),
                hashed_key, value);
            error = 0;
        }
    }
    return error;
}
