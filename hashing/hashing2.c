#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int data[SIZE];
int nextIndex[SIZE];
int avail = 0;

void displayList(int start) 
{
    int current = start;
    printf("\nIndex\tValue\tNext Index\n");
    while (current != -1) 
    {
        printf("%d\t%d\t%d\n", current, data[current], nextIndex[current]);
        current = nextIndex[current];
    }
}

int allocateNode() 
{
    if (avail == SIZE - 1) 
    {
        printf("Overflow: No more space available.\n");
        return -1;
    }
    int newNode = avail;
    avail++;
    return newNode;
}

void insertAtStart(int num, int *start) 
{
    int newNode = allocateNode();
    if (newNode == -1) 
    {
        return;
    }
    data[newNode] = num;
    nextIndex[newNode] = *start;
    *start = newNode;
}

void insertAtEnd(int num, int *start) 
{
    int newNode = allocateNode();
    if (newNode == -1) 
    {
        return;
    }
    data[newNode] = num;
    nextIndex[newNode] = -1;
    
    if (*start == -1) 
    {
        *start = newNode;
    } 
    else 
    {
        int current = *start;
        while (nextIndex[current] != -1) 
        {
            current = nextIndex[current];
        }
        nextIndex[current] = newNode;
    }
}

void insertAtMid(int num, int *start, int k) 
{
    int newNode = allocateNode();
    if (newNode == -1) 
    {
        return;
    }
    data[newNode] = num;
    nextIndex[newNode] = nextIndex[k];
    nextIndex[k] = newNode;
}

void deleteFirst(int *start) 
{
    if (*start != -1) 
    {
        int temp = *start;
        *start = nextIndex[*start];
        nextIndex[temp] = avail;
        avail = temp;
    }
}

void deleteLast(int *start) 
{
    if (*start == -1) 
    {
        return;
    }
    int current = *start;
    int prev = -1;
    while (nextIndex[current] != -1) 
    {
        prev = current;
        current = nextIndex[current];
    }
    if (prev == -1) 
    {
        *start = -1;
    } 
    else 
    {
        nextIndex[prev] = -1;
    }
    nextIndex[current] = avail;
    avail = current;
}

void deleteMid(int *start, int k) 
{
    int current = *start;
    int prev = -1;
    while (current != k) 
    {
        prev = current;
        current = nextIndex[current];
    }
    nextIndex[prev] = nextIndex[current];
    nextIndex[current] = avail;
    avail = current;
}

void searchElement(int start, int num) 
{
    int current = start;
    int index = 0;
    while (current != -1) 
    {
        index++;
        if (data[current] == num) 
        {
            printf("\n%d is present at index %d\n", num, index);
            return;
        }
        current = nextIndex[current];
    }
    printf("\n%d is not found in the list\n", num);
}

void sortList(int *start) 
{
    for (int i = *start; i != -1; i = nextIndex[i]) 
    {
        for (int j = nextIndex[i]; j != -1; j = nextIndex[j]) 
        {
            if (data[i] > data[j]) 
            {
                int tempData = data[i];
                data[i] = data[j];
                data[j] = tempData;
            }
        }
    }
}

int main() 
{
    int n;
    printf("N: ");
    scanf("%d", &n);

    int start = -1;
    
    for (int i = 0; i < SIZE; i++) 
    {
        nextIndex[i] = i + 1;
    }
    nextIndex[SIZE - 1] = -1;

    for (int i = 0; i < n; i++) 
    {
        int num;
        printf("Enter N%d: ", i + 1);
        scanf("%d", &num);
        insertAtEnd(num, &start);
    }

    displayList(start);

    while (1) 
    {
        int condition;
        printf("\n1. Display\n2. Insert at Start\n3. Insert at Mid\n4. Insert at End\n5. Delete First\n6. Delete Mid\n7. Delete Last\n8. Search\n9. Sort\n0. Exit\n");
        scanf("%d", &condition);

        switch (condition) 
        {
            case 1:
                displayList(start);
                break;
            case 2:
                printf("Enter the number: ");
                int num;
                scanf("%d", &num);
                insertAtStart(num, &start);
                displayList(start);
                break;
            case 3:
                printf("Enter the number: ");
                scanf("%d", &num);
                int k;
                printf("Enter the index after which to insert: ");
                scanf("%d", &k);
                insertAtMid(num, &start, k);
                displayList(start);
                break;
            case 4:
                printf("Enter the number: ");
                scanf("%d", &num);
                insertAtEnd(num, &start);
                displayList(start);
                break;
            case 5:
                deleteFirst(&start);
                displayList(start);
                break;
            case 6:
                printf("Enter the index to delete: ");
                scanf("%d", &k);
                deleteMid(&start, k);
                displayList(start);
                break;
            case 7:
                deleteLast(&start);
                displayList(start);
                break;
            case 8:
                printf("Enter the number to search: ");
                scanf("%d", &num);
                searchElement(start, num);
                break;
            case 9:
                sortList(&start);
                displayList(start);
                break;
            case 0:
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid input! Try again.\n");
                break;
        }
    }

    return 0;
}