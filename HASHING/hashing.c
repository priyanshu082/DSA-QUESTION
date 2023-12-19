#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 50
#define NUM_VALUES 40

// Hash function: k mod 47
int hashFunction(int key)
{
    return key % TABLE_SIZE;
}


// hash function 2
int secondHashFunction(int key)
{
    return 7 - (key % 7);
}





// Hash table structure
struct HashNode
{
    int key;
    int value;
};

typedef struct HashNode HashNode;

// Initialize hash table
void initializeTable(HashNode table[])
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i].key = -1; // Mark as empty
    }
}

// Insert using linear probing
int linearProbeInsert(HashNode table[], int key, int value, int probes)
{
    int index = hashFunction(key);
    probes = 0;
    while (table[index].key != -1)
    {
        index = (index + 1) % TABLE_SIZE; // Linear probing
        probes++;
    }

    table[index].key = key;
    table[index].value = value;
    return probes;
}


// deletion byh linear
void linearDelete(HashNode table[], int key)
{
    int index = hashFunction(key);

    while (table[index].key != -1)
    {
        if (table[index].key == key)
        {
            table[index].key = -1; // Mark as deleted
            printf("Key %d deleted using Linear Probing\n", key);
            return;
        }
        index = (index + 1) % 47;
    }

    printf("Key %d not found\n", key);
}

// quadratic
int quadraticProbe(int key, int i)
{
    return (key + i * i) % 47;
}

// Insert using quadratic probing
int quadraticProbeInsert(HashNode table[], int key, int value, int probes)
{
    int index = hashFunction(key);
    int i = 1;
    probes = 0;

    while (table[index].key != -1)
    {
        index = (index + i * i) % 47; // Quadratic probing
        probes++;
        i++;
    }

    table[index].key = key;
    table[index].value = value;
    return probes;
}

// delete

void quadraticDelete(HashNode table[], int key)
{
    int index = hashFunction(key);
    int originalIndex = index;
    int i = 1;

    while (table[index].key != -1)
    {
        if (table[index].key == key)
        {
            table[index].key = -1; // Mark as deleted
            printf("Key %d deleted using Quadratic Probing\n", key);
            return;
        }
        index = (originalIndex + i * i) % TABLE_SIZE;
        i++;
    }

    printf("Key %d not found\n", key);
}

// double hashing
int doubleHash(int key, int i)
{
    return (hashFunction(key) + i * secondHashFunction(key)) % 47;
}

// Insert a key-value pair using double hashing
int doubleHashInsert(HashNode table[], int key, int value, int probes)
{
    int index = hashFunction(key);
    int i = 0;
    probes = 0;

    while (table[index].key != -1)
    {
        i++;
        index = doubleHash(key, i);
        probes++;
    }

    table[index].key = key;
    table[index].value = value;
    return probes;
}

// Delete a key-value pair using double hashing
void doubleHashDelete(HashNode table[], int key)
{
    int index = hashFunction(key);
    int i = 0;

    while (table[index].key != -1)
    {
        if (table[index].key == key)
        {
            table[index].key = -1; // Mark as deleted
            return;
        }
        i++;
        index = doubleHash(key, i);
    }
}

// searching

int linearProbeSearch(HashNode table[], int key)
{
    int index = hashFunction(key);
    int attempt = 0;

    while (table[index].key != -1)
    {
        if (table[index].key == key)
        {
            return index;
        }
        attempt++;
        index = (index + 1) % TABLE_SIZE; // Linear probing
    }

    return -1;
}

// Search using quadratic probing
int quadraticProbeSearch(HashNode table[], int key)
{
    int index = hashFunction(key);
    int i = 0;

    while (table[index].key != -1)
    {
        if (table[index].key == key)
        {
            return index;
        }
        i++;
        index = quadraticProbe(index, i); // Quadratic probing
    }

    return -1;
}

// Search using double hashing
int doubleHashSearch(HashNode table[], int key)
{
    int index = hashFunction(key);
    int attempt = 0;

    while (table[index].key != -1)
    {
        if (table[index].key == key)
        {
            return index;
        }
        attempt++;
        index = doubleHash(index, key); // Double hashing
    }

    return -1;
}

void ask(int value, int key)
{
    printf("\nEnter key: ");
    scanf("%d", &key);
    printf("Enter value: ");
    scanf("%d", &value);
}
// Print the hash table
void printTable(HashNode table[])
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i].key != -1)
        {
            printf("Index: %d | Key: %d | Value: %d\n", i, table[i].key, table[i].value);
        }
        else
        {
            printf("Index: %d | Empty\n", i);
        }
    }
}

int main()
{
    int probes;
    HashNode hashTable[TABLE_SIZE];
    initializeTable(hashTable);

    srand(time(NULL));

    for (int i = 0; i < NUM_VALUES; i++)
    {
        int key = rand() % 1000;
        int value = rand() % 10000;
        linearProbeInsert(hashTable, key, value, probes);
    }

    printf("Initial Hash Table:\n");
    printTable(hashTable);
    printf("\n");
    int quad, dob;
    int key, value, choice, method;
    while (1)
    {
        printf("\nOptions:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Print Hash Tables\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5)
        {
            break;
        }

        if (choice != 4)
        {

            printf("Select collision resolution method:\n");
            printf("1. Linear Probing\n");
            printf("2. Quadratic Probing\n");
            printf("3. Double Hashing\n");
            printf("4. Separate Chaining\n");
            printf("Enter method: ");
            scanf("%d", &method);
        }

        switch (choice)
        {

        case 1:
            switch (method)
            {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value=");
                scanf("%d", &value);
                probes = linearProbeInsert(hashTable, key, value, probes);
                printf("\nInserted.\nprobes=%d", probes);
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value=");
                scanf("%d", &value);
                probes = quadraticProbeInsert(hashTable, key, value, probes);
                printf("\nInserted.\nprobes=%d", probes);
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value=");
                scanf("%d", &value);
                probes = doubleHashInsert(hashTable, key, value, probes);
                printf("\nInserted.\nProbes=%d", probes);
                break;
            }
            break;

        case 2:
            switch (method)
            {
            case 1:
                printf("\nEnter Key=");
                scanf("%d", &key);
                int linearIndex = linearProbeSearch(hashTable, key);

                if (linearIndex != -1)
                {
                    printf("Found at index %d (Double Hashing)\n", linearIndex);
                }
                else
                {
                    printf("Not found (Double Hashing)\n");
                }
                linearProbeSearch(hashTable, key);
                break;
            case 2:
                printf("\nEnter Key=");
                scanf("%d", &key);
                int quadIndex = quadraticProbeSearch(hashTable, key);

                if (quadIndex != -1)
                {
                    printf("Found at index %d (Double Hashing)\n", quadIndex);
                }
                else
                {
                    printf("Not found (Double Hashing)\n");
                }
                break;
            case 3:
                printf("\nEnter Key=");
                scanf("%d", &key);
                int doubleHashIndex = doubleHashSearch(hashTable, key);
                if (doubleHashIndex != -1)
                {
                    printf("Found at index %d (Double Hashing)\n", doubleHashIndex);
                }
                else
                {
                    printf("Not found (Double Hashing)\n");
                }

                break;
                // case 4:
                //     // Handle separate chaining search here
                //     break;
            }
            break;

        case 3:
            switch (method)
            {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                linearDelete(hashTable, key);
                printf("\nDeleted.\n");
                break;
            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                quadraticDelete(hashTable, key);
                printf("\nDeleted.\n");
                break;
            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                doubleHashDelete(hashTable, key);
                printf("\nDeleted.\n");
                break;
            }
            break;

        case 4:
            printTable(hashTable);
            printf("\n");
            break;
        }
    }

    return 0;
}