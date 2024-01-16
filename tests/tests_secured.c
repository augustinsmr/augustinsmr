/*
** EPITECH PROJECT, 2024
** secured
** File description:
** tests_secured.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/hashtable.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(create_ht, create_non_empty_table)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    cr_assert_eq(ht[0].index, 0);
    cr_assert_eq(ht[1].index, 1);
    cr_assert_eq(ht[2].index, 2);
    cr_assert_eq(ht[3].index, 3);
    cr_assert_eq(ht[4].index, 4);
    cr_assert_eq(ht[5].index, -1);
}

Test(dump, dump_empty, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    ht_dump(ht);
    cr_assert_stdout_eq_str("[0]:\n[1]:\n[2]:\n[3]:\n[4]:\n");
}

Test(dump, dump_not_empty, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    ht_insert(ht, "Kratos", "./Trash/Hollidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    ht_dump(ht);
    cr_assert_stdout_neq_str("[0]:\n[1]:\n[2]:\n[3]:\n[4]:\n");
}


Test(dump, delete, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    ht_delete(ht, "<3");
    ht_dump(ht);
    cr_assert_stdout_eq_str("[0]:\n[1]:\n[2]:\n[3]:\n[4]:\n");
}

Test(dump, delete_ht, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    delete_hashtable(ht);
}

Test(dump, null, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    ht_insert(ht, NULL, "+33 6 31 45 61 23 71");
    ht_insert(ht, "wawa", NULL);
    delete_hashtable(ht);
}

Test(dump, change_value, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 1);

    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Hollidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "a");
    ht_insert(ht, "pumpkin", "b");
    ht_insert(ht, "layout", "c");
    ht_insert(ht, "wawa", "bap");
    ht_insert(ht, "symptom", "d");
    ht_insert(ht, "suggest", "e");
    ht_insert(ht, "stop", "f");
    ht_insert(ht, "agency", "g");
    ht_insert(ht, "wawa", "bop");
    delete_hashtable(ht);
}

Test(dump, different_hash, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Hollidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "a");
    ht_insert(ht, "pumpkin", "b");
    ht_insert(ht, "layout", "c");
    ht_insert(ht, "symptom", "d");
    ht_insert(ht, "suggest", "e");
    ht_insert(ht, "stop", "f");
    ht_insert(ht, "agency", "g");
    ht_insert(ht, "football", "h");
    ht_insert(ht, "lend", "i");
    ht_insert(ht, "d", "j");
    ht_insert(ht, "buy", "k");
    ht_insert(ht, "passion", "l");
    ht_insert(ht, "regard", "m");
    ht_insert(ht, "medieval", "n");
    ht_insert(ht, "ewaggerate", "o");
    ht_insert(ht, "gtGRE", "p");
    ht_insert(ht, "YTD", "p");
    ht_insert(ht, "FZEQF", "p");
    ht_insert(ht, "zfef", "p");

    delete_hashtable(ht);
}

Test(dump, delete_in_hash, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Hollidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "a");
    ht_insert(ht, "pumpkin", "b");
    ht_insert(ht, "layout", "c");
    ht_insert(ht, "symptom", "d");
    ht_insert(ht, "suggest", "e");
    ht_insert(ht, "stop", "f");
    ht_insert(ht, "agency", "g");
    ht_insert(ht, "football", "h");
    ht_insert(ht, "lend", "i");
    ht_insert(ht, "d", "j");
    ht_insert(ht, "buy", "k");
    ht_insert(ht, "passion", "l");
    ht_insert(ht, "regard", "m");
    ht_insert(ht, "medieval", "n");
    ht_insert(ht, "ewaggerate", "o");
    ht_insert(ht, "gtGRE", "p");
    ht_insert(ht, "YTD", "p");
    ht_insert(ht, "FZEQF", "p");
    ht_insert(ht, "zfef", "p");
    ht_delete(ht, "layout");

    delete_hashtable(ht);
}

Test(dump, delete_null, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Hollidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "a");
    ht_insert(ht, "pumpkin", "b");
    ht_insert(ht, "layout", "c");
    ht_insert(ht, "symptom", "d");
    ht_insert(ht, "suggest", "e");
    ht_insert(ht, "stop", "f");
    ht_insert(ht, "agency", "g");
    ht_insert(ht, "football", "h");
    ht_insert(ht, "lend", "i");
    ht_insert(ht, "d", "j");
    ht_insert(ht, "buy", "k");
    ht_insert(ht, "passion", "l");
    ht_insert(ht, "regard", "m");
    ht_insert(ht, "medieval", "n");
    ht_insert(ht, "ewaggerate", "o");
    ht_insert(ht, "gtGRE", "p");
    ht_insert(ht, "YTD", "p");
    ht_insert(ht, "FZEQF", "p");
    ht_insert(ht, "zfef", "p");
    ht_delete(ht, NULL);

    delete_hashtable(ht);
}

Test(dump, delete_not_exist, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Hollidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "a");
    ht_insert(ht, "pumpkin", "b");
    ht_insert(ht, "layout", "c");
    ht_insert(ht, "symptom", "d");
    ht_insert(ht, "suggest", "e");
    ht_insert(ht, "stop", "f");
    ht_insert(ht, "agency", "g");
    ht_insert(ht, "football", "h");
    ht_insert(ht, "lend", "i");
    ht_insert(ht, "d", "j");
    ht_insert(ht, "buy", "k");
    ht_insert(ht, "passion", "l");
    ht_insert(ht, "regard", "m");
    ht_insert(ht, "medieval", "n");
    ht_insert(ht, "ewaggerate", "o");
    ht_insert(ht, "gtGRE", "p");
    ht_insert(ht, "YTD", "p");
    ht_insert(ht, "FZEQF", "p");
    ht_insert(ht, "zfef", "p");
    ht_delete(ht, "bipboup");

    delete_hashtable(ht);
}

Test(dump, delete_zero, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 0);

    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Hollidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "a");
    ht_insert(ht, "pumpkin", "b");
    ht_insert(ht, "layout", "c");
    ht_insert(ht, "symptom", "d");
    ht_insert(ht, "suggest", "e");
    ht_insert(ht, "stop", "f");
    ht_insert(ht, "agency", "g");
    ht_insert(ht, "football", "h");
    ht_insert(ht, "lend", "i");
    ht_insert(ht, "d", "j");
    ht_insert(ht, "buy", "k");
    ht_insert(ht, "passion", "l");
    ht_insert(ht, "regard", "m");
    ht_insert(ht, "medieval", "n");
    ht_insert(ht, "ewaggerate", "o");
    ht_insert(ht, "gtGRE", "p");
    ht_insert(ht, "YTD", "p");
    ht_insert(ht, "FZEQF", "p");
    ht_insert(ht, "zfef", "p");
    ht_delete(ht, "bipboup");

    delete_hashtable(ht);
}

Test(dump, search, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_search(ht, "Vision");

    delete_hashtable(ht);
}

Test(dump, search_null, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 5);

    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_search(ht, NULL);

    delete_hashtable(ht);
}

Test(dump, search_zero, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 0);

    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_search(ht, NULL);

    delete_hashtable(ht);
}

Test(dump, hash, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 1);

    ht_insert(ht, "4", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "", "./Documents/Tournament/Modules/Vision");

    delete_hashtable(ht);
}