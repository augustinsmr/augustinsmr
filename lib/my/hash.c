/*
** EPITECH PROJECT, 2024
** secured
** File description:
** hash.c
*/

#include "../../include/hashtable.h"

int my_compute_square_root(int nb)
{
    int tour = 0;
    int compt = 1;

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

int size_nb(int nb)
{
    int temp = nb;
    int i = 0;

    while (temp > 0) {
        temp /= 10;
        i ++;
    }
    return i;
}

int hash_next(int size, int end, int mod, int len)
{
    if (size > 0 && size < 5)
        return end * (my_compute_square_root(end) * mod);
    else if (size == 5)
        return end * len;
    else
        return end / (mod * size * 2);
}

int hash(char *key, int len)
{
    int size = my_strlen(key);
    int end = 1;
    int mod;

    for (int i = 0; i < size; i ++) {
        if ((i % 3) == 0)
            end += (key[i] * key[i]);
        else
            end -= ((key[i] - (key[i] / 2)) + key[i]);
    }
    end *= end;
    mod = ((end / 10) % 10) + 1;
    if (mod > 5 && size != 0)
        end /= (size * mod);
    size = size_nb(end);
    return hash_next(size, end, mod, len);
}

int main(void)
{
    hashtable_t *ht = new_hashtable(&hash, 2);

    ht_insert(ht, "avion", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "zvion", "./Trash/Hollidays_Pics/.secret_folder/kratos.ai");
    ht_dump(ht);
    return 0;
}
