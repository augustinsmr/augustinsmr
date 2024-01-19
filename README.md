# Secured

Secured is a C project with that aim to introduce us to hash tables by :
+ Developing our own hash function
+ Creating our own hash table

## Library

Use 'make' to create the library containing the different functions. You then need to compile your main with it.

```bash
make
gcc [main] -L . -l:libhashtable.a
```
**Don't forget to include the hashtable header.**
```c
#include "include/hashtable.h"
```

## Usage

Heres' a basic example of how to use the library:
```c
include "include/hashtable.h"

int main(void)
{
    hashtable_t *ht = new_hashtable(&hash,4);
    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Hollidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    ht_insert(ht, "</3", "+33 7 51 49 01 38 11");
    ht_dump(ht);
    printf("Looking for \"%s\": \"%s\"\n", "Kratos", ht_search(ht, "Kratos"));
    return 0;
}
```
The code above display this:
```bash
./a.out
[0]:
> 3354428 - +33 7 51 49 01 38 11
> 13116 - +33 6 31 45 61 23 71
[1]:
> 1769199557 - ./Documents/Tournament/Modules/Vision
[2]:
> 1952572858 - ./Trash/Hollidays_Pics/.secret_folder/kratos.ai
[3]:
Looking for “Kratos”: “./Trash/Hollidays_Pics/.secret_folder/kratos.ai”
```

## Functions
### hash
```c
int hash(char *key ,int len);
```
The hash function is the central element of a hash table, defining which table index should be
used to store the data.

key being the value to be hashed and len being the size of the hash table.

Example:
```c
int main ( void )
{
    int size = 5;
    printf("Vision: %d\n", hash ("Vision", size));
    printf("Perception: %d\n", hash("Perception", size));
    printf("Fight: %d\n", hash("Fight", size));
    printf("Pathfinding %d\n", hash("Pathfinding", size));
    return 0;
}
```
```bash
./a.out
Vision: 1769199557
Perception: 1290224677
Fight: 1751607738
Pathfinding: 1296709920
```
### New hashtable

```c
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
```
The new_hashtable take a pointer to the hash function and the length of the new table (> 0). This function returns a pointer to a structure : 
```c
typedef struct hashtable_s {
    int (*hash)(char *, int);
    int index;
    hash_value_t *ht_values;
} hashtable_t;

typedef struct hash_value_s {
    int key;
    char *value;
    struct hash_value_s *next;
}hash_value_t;
```
+ key variable is the hashed key when used in insert (char * to int)
+ value variable is a string used to be updated when a key already present in the hashtable is inserted
+ hashtable_s is a structure containing a linked list used to store key with the same index

### Dump
```c
void ht_dump(hashtable_t *ht);
```
The ht_dump take a hashtable structure in parameter. This function displays the state of the hash table.
```c
int main(void)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    ht_dump(ht);
    return 0;
}
```
```bash
./a.out
[0]:
[1]:
[2]:
[3]:
```
### Insert

```c
int ht_insert(hashtable_t *ht, char *key, char *value);
```
The ht_insert function is used to insert a new element into the hash table. It’s the key parameter
that needs to be hashed to find out the index in which to store the value.

```c
int main(void)
{
    hashtable_t *ht = new_hashtable(&hash,4);
    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Hollidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    ht_insert(ht, "</3", "+33 7 51 49 01 38 11");
    ht_dump(ht);
    printf("Looking for \"%s\": \"%s\"\n", "Kratos", ht_search(ht, "Kratos"));
    return 0;
}
```
```bash
./a.out
[0]:
> 3354428 - +33 7 51 49 01 38 11
> 13116 - +33 6 31 45 61 23 71
[1]:
> 1769199557 - ./Documents/Tournament/Modules/Vision
[2]:
> 1952572858 - ./Trash/Hollidays_Pics/.secret_folder/kratos.ai
[3]:
```
### Delete (Value)

```c
int ht_delete(hashtable_t *ht, char *key);
```
The ht_delete function will delete a value from the table. It hash the key, go to the given index
and then delete the value associated with this hash.
```c
int main(void)
{
    hashtable_t *ht = new_hashtable(&hash,4);
    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Hollidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    ht_delete(ht, "Vision");
    ht_dump(ht);
    return 0;
}
```
```bash
./a.out
[0]:
> 13116 - +33 6 31 45 61 23 71
[1]:
[2]:
> 1952572858 - ./Trash/Hollidays_Pics/.secret_folder/kratos.ai
[3]:
```
### Search
```c
char *ht_search(hashtable_t *ht, char *key);
```
The ht_search function takes a key as a parameter, then hashes it to access the index. If the value
matches the hash, then the value is returned.
```c
int main(void)
{
    hashtable_t *ht = new_hashtable(&hash,4);
    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Hollidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    ht_dump(ht);
    printf("Looking for \"%s\": \"%s\"\n", "Kratos", ht_search(ht, "Kratos"));
    return 0;
}
```
```bash
./a.out
[0]:
> 13116 - +33 6 31 45 61 23 71
[1]:
> 1769199557 - ./Documents/Tournament/Modules/Vision
[2]:
> 1952572858 - ./Trash/Hollidays_Pics/.secret_folder/kratos.ai
[3]:
Looking for “Kratos”: “./Trash/Hollidays_Pics/.secret_folder/kratos.ai”
```
### Delete (hashtable)
```c
void delete_hashtable(hashtable_t *ht);
```
The delete_hashtable function take the table in parameter and destroy all the values that are inside and the table itself.

## Unit tests
The 'tests' folder is used to create unit tests with the criterion library.

To launch the tests:
```bash
make tests_run
> [====] Synthesis: Tested: 16 | Passing: 16 | Failing: 0 | Crashing: 0
```
To see the coverage:
```bash
gcovr --exclude tests/
> ------------------------------------------------------------------------------
                           GCC Code Coverage Report
Directory: .
------------------------------------------------------------------------------
File                                       Lines    Exec  Cover   Missing
------------------------------------------------------------------------------
lib/my/create_ht.c                            13      13   100%
lib/my/delete_hashtable.c                     17      17   100%
lib/my/dump.c                                 17      16    94%   16
lib/my/hash.c                                 36      34    94%   17,43
lib/my/ht_delete.c                            26      26   100%
lib/my/insert_ht.c                            48      44    91%   46-49
lib/my/my_put_nbr.c                            7       7   100%
lib/my/my_putchar.c                            3       3   100%
lib/my/my_putstr.c                             4       0     0%   10,12-13,15
lib/my/my_strcpy.c                             7       7   100%
lib/my/my_strlen.c                             5       5   100%
lib/my/search_ht.c                            19      19   100%
------------------------------------------------------------------------------
TOTAL                                        202     191    94%
------------------------------------------------------------------------------
```
To see branch coverage:
```bash
gcovr --exclude tests/ --branches
> ------------------------------------------------------------------------------
                           GCC Code Coverage Report
Directory: .
------------------------------------------------------------------------------
File                                    Branches   Taken  Cover   Missing
------------------------------------------------------------------------------
lib/my/create_ht.c                             4       4   100%
lib/my/delete_hashtable.c                      6       6   100%
lib/my/dump.c                                  6       5    83%   15
lib/my/hash.c                                 20      16    80%   16,40,42,62
lib/my/ht_delete.c                            16      15    93%   42
lib/my/insert_ht.c                            24      22    91%   45,71
lib/my/my_put_nbr.c                            2       2   100%
lib/my/my_putchar.c                            0       0    --%
lib/my/my_putstr.c                             2       0     0%   12
lib/my/my_strcpy.c                             2       2   100%
lib/my/my_strlen.c                             2       2   100%
lib/my/search_ht.c                            14      13    92%   30
------------------------------------------------------------------------------
TOTAL                                         98      87    88%
------------------------------------------------------------------------------
```
