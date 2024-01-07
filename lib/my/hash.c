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
    if (size > 0 && size < 5)
        end *= (my_compute_square_root(end) * mod);
    else
        end /= (mod * size * 2);
    return end;
}

int main(void)
{
    hashtable_t *ht = new_hashtable(&hash, 3);

    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Hollidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    ht_insert(ht, "pumpkin", "+33 7 51 49 01 38 11");
    ht_insert(ht, "layout", "+33 7 51 49 01 38 11");
    ht_insert(ht, "symptom", "+33 7 51 49 01 38 11");
    ht_insert(ht, "suggest", "+33 7 51 49 01 38 11");
    ht_insert(ht, "stop", "+33 7 51 49 01 38 11");
    ht_insert(ht, "agency", "+33 7 51 49 01 38 11");
    ht_insert(ht, "football", "+33 7 51 49 01 38 11");
    ht_insert(ht, "lend", "+33 7 51 49 01 38 11");
    ht_insert(ht, "drop", "+33 7 51 49 01 38 11");
    ht_insert(ht, "buy", "+33 7 51 49 01 38 11");
    ht_insert(ht, "passion", "+33 7 51 49 01 38 11");
    ht_insert(ht, "regard", "+33 7 51 49 01 38 11");
    ht_insert(ht, "medieval", "+33 7 51 49 01 38 11");
    ht_insert(ht, "ewaggerate", "+33 7 51 49 01 38 11");
    ht_insert(ht, "dilemma", "+33 7 51 49 01 38 11");
    ht_dump(ht);
    return 0;
}
