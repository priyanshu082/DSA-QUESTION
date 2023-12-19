#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Hash function: key mod TABLE_SIZE
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

int main() {
    int hashTable[TABLE_SIZE]; // The hash table as an array
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1; // Initialize the hash table with -1 (empty)
    }

    printf("Enter the number of values to insert: ");
    int numValues;
    scanf("%d", &numValues);

    for (int i = 0; i < numValues; i++) {
        int value;
        printf("Enter a value: ");
        scanf("%d", &value);

        int index = hashFunction(value); // Calculate the hash index using the hash function
        int originalIndex = index;

        // Linear probing: Keep probing until an empty slot is found
        while (hashTable[index] != -1) {
            index = (index + 1) % TABLE_SIZE;
            // If we looped back to the original index, the hash table is full
            if (index == originalIndex) {
                printf("Hash table is full, cannot insert value %d.\n", value);
                break;
            }
        }

        // If we didn't encounter a full hash table, insert the value
        if (hashTable[index] == -1) {
            hashTable[index] = value;
            printf("Inserted %d at index %d.\n", value, index);
        }
    }

    // Display the final hash table
    printf("\nFinal Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d: %d\n", i, hashTable[i]);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }

    return 0;
}
