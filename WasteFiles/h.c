#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 50
#define NUM_VALUES 40

struct HashNode {
    int key;
    int value;
};

typedef struct HashNode HashNode;

void initializeTable(HashNode table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].key = -1;
    }
}

int linearProbeInsert(HashNode table[], int key, int value, int *probes) {
    int index = key % TABLE_SIZE;
    *probes = 0;

    while (table[index].key != -1) {
        index = (index + 1) % TABLE_SIZE;
        (*probes)++;
    }

    table[index].key = key;
    table[index].value = value;
    return *probes;
}

void linearDelete(HashNode table[], int key) {
    int index = key % TABLE_SIZE;

    while (table[index].key != -1) {
        if (table[index].key == key) {
            table[index].key = -1;
            printf("Key %d deleted using Linear Probing\n", key);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    }

    printf("Key %d not found\n", key);
}

int linearProbeSearch(HashNode table[], int key) {
    int index = key % TABLE_SIZE;

    while (table[index].key != -1) {
        if (table[index].key == key) {
            return index;
        }
        index = (index + 1) % TABLE_SIZE;
    }

    return -1;
}

void printTable(HashNode table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].key != -1) {
            printf("Index: %d | Key: %d | Value: %d\n", i, table[i].key, table[i].value);
        } else {
            printf("Index: %d | Empty\n", i);
        }
    }
}

int main() {
    int probes;
    HashNode hashTable[TABLE_SIZE];
    initializeTable(hashTable);

    srand(time(NULL));

    for (int i = 0; i < NUM_VALUES; i++) {
        int key = rand() % 1000;
        int value = rand() % 10000;
        linearProbeInsert(hashTable, key, value, &probes);
    }

    printf("Initial Hash Table:\n");
    printTable(hashTable);
    printf("\n");

    int key, choice;
    while (1) {
        printf("\nOptions:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Print Hash Table\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            break;
        }

        printf("Enter key: ");
        scanf("%d", &key);

        switch (choice) {
            case 1:
                int value;
                printf("Enter value: ");
                scanf("%d", &value);
                probes = linearProbeInsert(hashTable, key, value, &probes);
                printf("\nInserted.\nProbes: %d\n", probes);
                break;
            case 2:
                int index = linearProbeSearch(hashTable, key);
                if (index != -1) {
                    printf("Found at index %d (Linear Probing)\n", index);
                } else {
                    printf("Not found (Linear Probing)\n");
                }
                break;
            case 3:
                linearDelete(hashTable, key);
                printf("\nDeleted.\n");
                break;
            case 4:
                printTable(hashTable);
                printf("\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
