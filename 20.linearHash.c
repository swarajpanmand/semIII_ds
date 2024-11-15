#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TABLE_SIZE 10
#define EMPTY -1

typedef struct HashTable
{
    int *table;
} HashTable;

int hashFunction(int key)
{
    return key % 10;
}

HashTable *createTable()
{
    HashTable *ht = (HashTable *)malloc(TABLE_SIZE * sizeof(HashTable));
    ht->table = (int *)malloc(TABLE_SIZE * sizeof(int));
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        ht->table[i] = EMPTY;
    }
    return ht;
}

void insert(HashTable *ht, int key)
{
    int index = hashFunction(key);
    int startIndex = index;

    while (ht->table[index] != EMPTY && ht->table[index] != key)
    {
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex)
        {
            printf("Table is full\n");
            return;
        }
    }
    if (ht->table[index] == key)
    {
        printf("Duplicate key\n");
        return;
    }
    else
    {
        ht->table[index] = key;
        printf("Key %d inserted at index %d\n", key, index);
    }
}

int search(HashTable *ht, int key)
{
    int index = hashFunction(key);
    int startIndex = index;

    while (ht->table[index] != EMPTY)
    {
        if (ht->table[index] == key)
        {
            return index;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex)
        {
            break;
        }
    }

    return -1;
}

int main(){
    HashTable * ht = createTable();
    insert(ht, 12);
    insert(ht, 25);
    insert(ht, 35);
    insert(ht, 26);
    insert(ht, 45);
    insert(ht, 55);
    insert(ht, 65);
    insert(ht, 75);
    insert(ht, 85);
    insert(ht, 95);
    insert(ht, 105);

    int index = search(ht, 25);
    if(index != -1){
        printf("Key found at index %d\n", index);
    }else{
        printf("Key not found\n");
    }

    return 0;
}