#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1
#define DELETED -2

typedef struct HashTable{
    int *table;
} HashTable;

HashTable *createHashTable(){
    HashTable * ht = (HashTable*)malloc(sizeof(HashTable));
    ht->table = (int*)malloc(TABLE_SIZE * sizeof(int));
    for(int i=0;i<TABLE_SIZE; i++){
        ht->table[i]= EMPTY;
    }
    return ht;
}

int hashFunction(int key){
    return key % TABLE_SIZE;
}

void insert(HashTable *ht, int key){
    int index =hashFunction(key);
    int startIndex = index;
    int i=0;

    while(ht->table[index]!=EMPTY && ht->table[index]!=DELETED && ht->table[index]!=key){
        index = (startIndex + i*i) % TABLE_SIZE;
        i++;
        if(i == TABLE_SIZE){
            printf("Table is full\n");
            return;
        }
    }

    if(ht->table[index]==key){
        printf("Duplicate key\n");
        return;
    }
    else{
        ht->table[index]=key;
        printf("Key %d inserted at index %d\n", key, index);
    }

}

int search(HashTable *ht, int key){
    int index = hashFunction(key);
    int startIndex = index;
    int i=0;

    while(ht->table[index]!=EMPTY && ht->table[index]!=key){
        index = (startIndex + i*i) % TABLE_SIZE;
        i++;
        if(i == TABLE_SIZE){
            return -1;
        }
    }

    if(ht->table[index]==key){
        return index;
    }
    else{
        return -1;
    }
}

int main(){
    HashTable * ht = createHashTable();
    insert(ht, 12);
    insert(ht, 25);
    insert(ht, 35);
    insert(ht, 26);
    insert(ht, 45);
    insert(ht, 85);
    insert(ht, 95);
    insert(ht, 75);
    insert(ht, 65);
    insert(ht, 55);
    insert(ht, 15);
    insert(ht, 5);

    int index = search(ht, 25);
    if(index != -1){
        printf("Key found at index %d\n", index);
    }else{
        printf("Key not found\n");
    }

    return 0;
}