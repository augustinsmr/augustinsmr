/*
** EPITECH PROJECT, 2024
** secured
** File description:
** hash.c
*/

#include "../../include/hashtable.h"

int my_compute_square_root(int nb)
{
    int     tour = 0;
    int     compt = 1;

    while (nb != 0){
        if (nb < 0){
            return (0);
        }
        nb = nb - compt;
        compt = compt + 2;
        tour ++;
    }
    return (tour);
}

int hash(char *key, int len)
{
    int size = my_strlen(key);
    unsigned int end = 1;

    for (int i = 0; i < size; i ++) {
        if ((i % 3) == 0)
            end += (key[i] * key[i]);
        else
            end -= ((key[i] * key[i]) + key[i]);
    }
    if (size < 4)
        end /= 2;
    end *= end;
    if (size > 8 && len != 0)
        end /= (((int)(size / 3)) * (len * len));
    if (size > 4 && size < 8)
        end = my_compute_square_root(end) * size;
    return end;
}

int main(void)
{
    hashtable_t *ht = new_hashtable(&hash, 4);

    for (int i; i < 4; i ++) {
        printf("%d\n", ht[i].index);
    }
    printf("V: %d\n", hash("Vi", 1));
    printf("Perception : %d\n", hash("Perception", 2));
    printf("Fight : %d\n", hash("Fight", 1));
    printf("Pathfinding %d\n", hash("Perception", 3));
    return 0;
}
