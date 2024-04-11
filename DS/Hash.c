#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
 * Data Structure
 */
typedef struct _list_t {
    struct _list_t *next;
    char *string; // Key
} list_t;

typedef struct _hash_table_t_ {
    unsigned int hash_bucket_size;
    list_t **table;
} hash_table_t;

/*
 * Global declaration
 */
hash_table_t *my_hash_table;
int size_of_table = 12;

/*
 *  Forward declaration
 */
hash_table_t *create_hash_table (unsigned int size);
unsigned int hash(hash_table_t *hashtable, char *key);
int hash_insert(hash_table_t *table, char *key);
list_t *hash_find(hash_table_t *table, char *key);
void hash_traverse(hash_table_t *table);
void destroy_hash_table(hash_table_t **table);

/*
 * Functions
 */
hash_table_t *
create_hash_table(unsigned int size)
{
    hash_table_t *new_table;
    int i;

    if (size < 1) 
        return NULL; /* invalid size for table */
    /*
     * allocate memory for the table structure 
     */
    if ((new_table = malloc(sizeof(hash_table_t))) == NULL) {
        return NULL;
    }
    /*
     * allocate Table itself 
     */
    if ((new_table->table = malloc(sizeof(list_t *)*size)) == NULL) {
        return NULL;
    }
    /*
     * Initialize the elements of the table
     */
    for (i = 0; i < size; i++) {
        new_table->table[i] = NULL;
    }
    /*
     * set the hash table size
     */
    new_table->hash_bucket_size = size;

    return new_table;
}

unsigned int
hash (hash_table_t *table, char *key)
{
    unsigned int hashval;

    /* Start with hash_val 0 */
    hashval = 0;
    
    for (; *key != '\0'; key++) {
        hashval = ((hashval << 5) - hashval) + *key;
    }

    return hashval % table->hash_bucket_size;
}

list_t *
hash_find (hash_table_t *hashtable, char *key)
{
    list_t *list;
    
    /* compute hash value from key */
    unsigned int hashval = hash(hashtable, key);

    /* traverse linearly */
    for (list = hashtable->table[hashval]; list != NULL; 
                           list = list->next) {
        if (strcmp(list->string, key) == 0)
            return list;
    }
    return NULL;
}

int
hash_insert (hash_table_t *hashtable, char *key)
{
    list_t *new_list;
    list_t *current_list;


    /* look up key if already exists */
    current_list = hash_find(hashtable, key);
    if (current_list != NULL)
        return -2; /* key exists */

    if ((new_list = malloc(sizeof(list_t))) == NULL)
        return -1;  /* no memory */

    /* insert new hash entry */
    new_list->string = (char *)strdup(key);
    /* compute has value from key */
    unsigned int hashval = hash(hashtable, key);
    new_list->next = hashtable->table[hashval];
    hashtable->table[hashval] = new_list;

    return 0; /* inserted successfully */
}

int
hash_delete (hash_table_t *hashtable, char *key)
{
    list_t *list;
    list_t *prev = NULL;

    int hashval;

    /* compute the hash from key */
    hashval = hash(hashtable, key);
    list = hashtable->table[hashval];

    /* find the key */
    while (list != NULL) {
        if ((strcmp(list->string, key)) == 0)
            break;
        prev = list;
        list = list->next;
    }

    if (list == NULL) {
        printf("Key %s not found\n", key);
        return -1; /* key not found */
    }

    if (prev == NULL) {
        hashtable->table[hashval] = list->next;
    } else {
        prev->next = list->next;
    }
    free(list->string);
    free(list);

    return 0;
}

void
hash_traverse (hash_table_t *hashtable)
{
    list_t *list;
    int    i;

    for (i = 0; i < hashtable->hash_bucket_size; i++) {
        list = hashtable->table[i];
        printf("Index %d: ", i);
        while (list != NULL) {
            printf("%s ", list->string);
            list = list->next;
        }
        printf("\n");
    }
}

void 
destroy_hash_table (hash_table_t **hashtable)
{
    int i;
    list_t *list;
    list_t *free_list;

    for (i = 0; i < (*hashtable)->hash_bucket_size; i ++){
        list = (*hashtable)->table[i];
        while (list != NULL) {
            free(list->string);
            free_list = list;
            list = list->next;
            free(free_list);
        }
    }
    free((*hashtable)->table);
    free(*hashtable);
}

int
main (int argc, char *arcv[])
{
    my_hash_table = create_hash_table(size_of_table);
    hash_insert(my_hash_table, "sanjeev");
    hash_insert(my_hash_table, "vishal");
    hash_insert(my_hash_table, "prachi");

    hash_traverse(my_hash_table);
    hash_delete(my_hash_table, "rajeev");
    hash_delete(my_hash_table, "sanjeev");
    hash_traverse(my_hash_table);
    destroy_hash_table(&my_hash_table);
}
