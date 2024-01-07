/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Secured
** File description:
** hashtable.h
*/

#ifndef HASHTABLE_H
    #define HASHTABLE_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>

typedef struct hash_value_s {
    int key;
    char *value;
    struct hash_value_s *next;
}hash_value_t;

typedef struct hashtable_s {
    int (*hash)(char *, int);
    int index;
    hash_value_t *ht_values;
} hashtable_t;

// Hash function
int hash(char *key, int len);

// Create & destro table
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);
int my_strlen(char const *str);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_put_nbr(int nb);
void my_putchar(char c);

#endif /* HASHTABLE_H */
