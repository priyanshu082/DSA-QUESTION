#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Node
{
    int data;
    struct Node* next;
};
struct Node* head;

void make_list();
void Search(struct Node* head);
void Insertion();
void Deletion();
void Display();

int main()
{
    srand(time(0));
    
       
    printf("Implement search, insertion and deletion operations on a Linked List.\n");
    printf("Enter the number of nodes in the linked list: ");
    int n;
    scanf("%d", &n);

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    for(int i = 0; i < n; i++)
    {
        make_list();               //this will create a linked list
    }
    printf("A linked list of %d nodes has been created using a random number generator.\n", n);

    int arr1[n];            //array to keep track of data stored in linked list
    struct Node* arr2[n];   //array to keep track of next pointers

    struct Node* head1 = (struct Node*)malloc(sizeof(struct Node));
    head1 = head;

    for(int i = 0; i < n; i++)
    {
        arr1[i] = head1->data;
        arr2[i] = head1->next;
        head1 = head1->next;
    }
    printf("\nNode\tData\tNext Pointer\n");
    for(int j = 0; j < n; j++)
    {
        printf("%d  \t%d  \t%p\n", j+1, arr1[j], arr2[j]);

    }
    printf("\n");

    printf("1 - Search\n");
    printf("2 - Insertion\n");
    printf("3 - Deletion\n");
    printf("4 - Display elements\n");
    printf("5 - Exit the program\n");
    printf("Enter the corresponding number of the operation you want to perform: ");
    int x;
    scanf("%d", &x);

    switch(x)
    {
        case 1:
        Search(head);
        break;

        case 2:
        Insertion();
        break;

        case 3:
        Deletion();
        break;

        case 4:
        Display();
        break;

        case 5:
        exit(0);

        default:
        printf("\nInvalid input\n");            
    }

}

void make_list()               //function to create a linked list
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = rand() % 100;
    temp->next = head;
    head = temp;
}

void Search(struct Node* head)          //function to search for an element
{
    Display();

    printf("\nEnter the number to search in the array: ");
    int x;
    scanf("%d", &x);

    struct Node* ptr = head;

    while(ptr != NULL)
    {
        if(ptr->data == x)
        {
            printf("The entered number %d was found in the linked list.\n", x);
            return;
        }
        ptr = ptr->next;
    }

    printf("The entered number %d was not found in the linked list.\n", x);
    return;

}

void Insertion()                //function to insert an element
{
    Display();

    printf("\nEnter the number to insert: ");
    int x;
    scanf("%d", &x);

    printf("Enter the position to insert the number: ");
    int n;
    scanf("%d", &n);
    
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = x;
    temp1->next = NULL;
    if (n == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    struct Node *temp2 = head;
    for (int i = 0; i < n - 2; i++)
    {
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;

    printf("The entered number %d has been inserted in the linked list.\n\n", x);
    Display();
}

void Deletion()                     //function to delete an element
{
    Display();

    printf("\nEnter the position of the element to delete: ");
    int n;
    scanf("%d", &n);

    struct Node *temp1 = head;
    if (n == 1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }
    for (int i = 0; i < n - 2; i++)
    {
        temp1 = temp1->next;
    }

    struct Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);

    printf("The element at position %d has been deleted.\n\n", n);
    Display();
}

void Display()         //function to display the elements
{
    struct Node* ptr = head;
    
    printf("Elements in the linked list are:\n[");
    while(ptr != NULL)
    {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }
    printf(" ]");
}