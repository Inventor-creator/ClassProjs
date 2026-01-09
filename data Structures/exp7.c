#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10


struct DataItem {
    char* key;
    int value;
};


struct DataItem* hashTable[TABLE_SIZE];


int hashCode(char* key) {
    int hash = 0;
    int len = strlen(key);
    for (int i = 0; i < len; i++) {
        hash = (hash + key[i]) % TABLE_SIZE;
    }
    return hash;
}


void insert(char* key, int value) {
    
    struct DataItem* item = (struct DataItem*)malloc(sizeof(struct DataItem));
    item->key = strdup(key);
    item->value = value;

    
    int hashIndex = hashCode(key);

    
    while (hashTable[hashIndex] != NULL) {
        
        ++hashIndex;
        
        hashIndex %= TABLE_SIZE;
    }
    hashTable[hashIndex] = item;
}


struct DataItem* search(char* key) {
    
    int hashIndex = hashCode(key);

    
    while (hashTable[hashIndex] != NULL) {
        if (strcmp(hashTable[hashIndex]->key, key) == 0)
            return hashTable[hashIndex];
        
        ++hashIndex;
        
        hashIndex %= TABLE_SIZE;
    }
    return NULL;
}


struct DataItem* delete(char* key) {
    
    int hashIndex = hashCode(key);

    
    while (hashTable[hashIndex] != NULL) {
        if (strcmp(hashTable[hashIndex]->key, key) == 0) {
            struct DataItem* temp = hashTable[hashIndex];
            
            hashTable[hashIndex] = NULL;
            return temp;
        }
        
        ++hashIndex;
        
        hashIndex %= TABLE_SIZE;
    }
    return NULL;
}


void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL)
            printf(" (%s, %d)", hashTable[i]->key, hashTable[i]->value);
        else
            printf(" ~~ ");
    }
    printf("\n");
}

int main() {
    
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    insert("one", 1);
    insert("two", 2);
    insert("three", 3);
    insert("four", 4);
    insert("five", 5);
    insert("six", 6);
    insert("seven", 7);
    insert("eight", 8);
    insert("nine", 9);
    insert("ten", 10);


    display();

    struct DataItem* item = search("five");
    if (item != NULL) {
        printf("Element found: %d\n", item->value);
    } else {
        printf("Element not found\n");
    }

    delete("five");
    item = search("five");
    if (item != NULL) {
        printf("Element found: %d\n", item->value);
    } else {
        printf("Element not found\n");
    }
    display();
}
