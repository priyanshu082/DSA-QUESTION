#include<stdio.h>
#include<stdlib.h>


//new structure is defined here that will store node ;
struct Node {
    int data;
    struct Node* next;
};

//function to print all the linkedlist
void transversal(struct Node *ptr ){
    while(ptr!=NULL){
    printf("Elemnet : %d\n" ,ptr->data);
    ptr=ptr->next;
    }
}

//function to insert at the starting of the linked list
struct Node * insertAtFirst(struct Node *head,int data){
    struct Node * newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->next=head;
    newNode->data=data;
    return newNode;
}

//function to add in between the linkedlist;
struct Node * insertAtIndex(struct Node *head,int data,int index){
    struct Node * newNode=(struct Node *)malloc(sizeof(struct Node));
    struct Node* p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    newNode->data=data;
    newNode->next=p->next;
    p->next=newNode;
    return head;
}

//function to add in the end of the array
struct Node * insertAtEnd(struct Node *head,int data){
    struct Node * newNode=(struct Node *)malloc(sizeof(struct Node));
    struct Node* p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    newNode->data=data;
    p->next=newNode;
    newNode->next=NULL;
    return head;
}

//function to delte a linkedlist


int main(){

    struct Node *head;
    struct Node *second;
    struct Node *third;
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    head->data=8;
    head->next=second;
    second->data=82;
    second->next=third;
    third->data=823;
    third->next=NULL;

//  head = insertAtFirst(head,56);
//  head = insertAtIndex(head,56,1);
//  head = insertAtIndex(head,453,4);
 head = insertAtEnd(head,453);


 transversal(head);

    return 0;
}